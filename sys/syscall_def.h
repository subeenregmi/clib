/* Copyright (C) 2024
 *
 * Author: Subeen Regmi <subeenregmi123@gmail.com>
 * Date: 2024-02-07
 *
 * These are all the x86_64 system calls that are defined in clib currently, 
 * and all the common file descriptors.
 */
#ifndef CLIB_SYSCALL_DEF_H
#define CLIB_SYSCALL_DEF_H

// Common File Descriptors
#define STDIN_FD        0
#define STDOUT_FD       1
#define STDERR_FD       2

// Linux x86 syscalls
#define SYS_READ        0
#define SYS_WRITE       1
#define SYS_OPEN        2
#define SYS_CLOSE       3

#endif // CLIB_SYSCALL_DEF_H
