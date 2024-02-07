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

int sys_write(int fd, String str) {
    return syscall((void*)SYS_WRITE, (void*)fd, str, (void*)str_length(str), 0, 0, 0);
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
/*
int main() {
    String s = "hello world";
    sys_write(STDOUT_FD, s);
    return 0;
}
*/
