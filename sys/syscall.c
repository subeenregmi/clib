#include "syscall.h"
#include "syscall_def.h"
#include "poll.h"

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

int sys_write(int fd, String str, unsigned int length) {
    return syscall((void*)SYS_WRITE, (void*)fd, str, (void*)length, 0, 0, 0);
}

int sys_read(int fd, String str, int bytes) {
    return syscall((void*)SYS_READ, (void*)fd, str, (void*)bytes, 0, 0, 0);
}

int sys_open(String filename, int flags, int mode) {
    return syscall((void*)SYS_OPEN, (void*)filename, (void*)flags, (void*)mode, 0, 0, 0);
}

int sys_close(int fd) {
    return syscall((void*)SYS_CLOSE, (void*)fd, 0, 0, 0, 0, 0);
}

int sys_poll(struct pollfd *poll, unsigned int n_polls, int timeout) {
    return syscall((void*)SYS_POLL, poll, (void*)n_polls, (void*)timeout, 0, 0, 0);
}

/*
int main() {
    String a = "Your name is ";
    String s = "What is your name?\n";
    sys_write(STDOUT_FD, s, str_length(s));
    String name;
    sys_read(STDIN_FD, name, 6);
    sys_write(STDOUT_FD, a, str_length(a));
    sys_write(STDOUT_FD, name, str_length(name));

    return 0;
}
*/
