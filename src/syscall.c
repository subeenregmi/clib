#include "syscall.h"
#include "syscall_def.h"

int syscall(void *arg1, void *arg2, void *arg3, void *arg4) {
    int ret;
    __asm__ volatile (
            "syscall"
            : "=a"(ret)
            :"a"(arg1), "D"(arg2), "S"(arg3), "d"(arg4)
            :"rcx", "r11", "memory"
            );
    return ret;
}

int sys_write(int fd, String str) {
    return syscall((void*)SYS_WRITE, (void*)fd, str, (void*)str_length(str));
}

int sys_read(int fd, String str, int bytes) {
    return syscall((void*)SYS_READ, (void*)fd, str, (void*)bytes);
}

int sys_open(String filename, int flags, int mode) {
    return syscall((void*)SYS_OPEN, (void*)filename, (void*)flags, (void*)mode);
}

int sys_close(int fd) {
    return syscall((void*)SYS_CLOSE, (void*)fd, 0, 0);
}
