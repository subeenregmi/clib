#include "syscall.h"
#include "syscall_def.h"

int syscall(void *NR, void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5) {
    int ret;
    register void *r10 asm("r10") = arg3; 
    register void *r8 asm("r8") = arg4; 
    register void *r9 asm("r9") = arg5; 
    __asm__ volatile (
            "syscall"
            : "=a"(ret)
            :"a"(NR), "D"(arg0), "S"(arg1), "d"(arg2), "r"(r10), "r"(r8), "r"(r9)
            :"rcx", "r11", "memory"
            );
    return ret;
}

int sys_write(ulint_t fd, String str, ulint_t length) {
    return syscall((void*)SYS_WRITE, (void*) fd, str, (void*)length, 0, 0, 0);
}

int sys_read(ulint_t fd, String str, ulint_t bytes) {
    return syscall((void*)SYS_READ, (void*)fd, str, (void*)bytes, 0, 0, 0);
}

int sys_open(String filename, ulint_t flags, ulint_t mode) {
    return syscall((void*)SYS_OPEN, (void*)filename, (void*)flags, (void*)mode, 0, 0, 0);
}

int sys_close(ulint_t fd) {
    return syscall((void*)SYS_CLOSE, (void*)fd, 0, 0, 0, 0, 0);
}

int sys_poll(struct pollfd *poll, ulint_t n_polls, int timeout) {
    return syscall((void*)SYS_POLL, poll, (void*)n_polls, (void*)timeout, 0, 0, 0);
}

int sys_lseek(ulint_t fd, int offset, ulint_t whence) {
    return syscall((void*)SYS_LSEEK, (void*)fd, (void*)offset, (void*)whence, 0, 0, 0);
}

int main() {
    String a = "Your name is ";
    String s = "What is your name?\n";
    sys_write(STDOUT_FD, s, str_length(s));
    char name[6];
    int counter = 0;

    struct pollfd mypoll;
    mypoll.fd = 0;
    mypoll.events = POLL_NREAD;
    mypoll.revents = 0;
    
    while (1) {
        if (sys_poll(&mypoll, 1, 1000) == 1) {
            sys_read(STDIN_FD, name, 6);
            sys_write(STDOUT_FD, a, str_length(a));
            sys_write(STDOUT_FD, name, 6);
            break;
        }
        else
            counter++;
    }
    return counter;
}
