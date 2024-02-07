/* Copyright (C) 2024
 *
 * Author: Subeen Regmi <subeenregmi123@gmail.com>
 * Date: 2024-02-07
 *
 * This is the clib wrapper for the x86_64 linux system calls.
 *
 * The syscall function is the generic system call. The functions below, 
 * just help to call a specific system call.
 *
 * Note: Some params are outlined in the flags/<syscall>.h directory, e.g:
 * open has its flags and mode params outlined in flags/open.h
 */
#ifndef CLIB_SYSCALL_H
#define CLIB_SYSCALL_H

#include "string.h"

int syscall(void *arg1, void *arg2, void *arg3, void *arg4);

int sys_write(int fd, String str);
int sys_read(int fd, String str, int bytes);
int sys_open(String filename, int flags, int mode);
int sys_close(int fd);

#endif // CLIB_SYSCALL_H

