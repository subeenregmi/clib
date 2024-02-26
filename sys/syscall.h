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
#ifndef CLIB_SYS_SYSCALL_H
#define CLIB_SYS_SYSCALL_H

#include "string.h"
#include "poll.h"

typedef unsigned long int ulint_t;

int syscall(void *NR, void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5);

int sys_write(ulint_t fd, String str, ulint_t length);
int sys_read(ulint_t fd, String str, ulint_t bytes);
int sys_open(String filename, ulint_t flags, ulint_t mode);
int sys_close(ulint_t fd);
int sys_poll(struct pollfd *poll, ulint_t n_polls, int timeout);
int sys_lseek(ulint_t fd, int offset, ulint_t whence);
int sys_mmap(ulint_t addr, ulint_t bytes, ulint_t prot, ulint_t flags, ulint_t fd, ulint_t offset);

#endif // CLIB_SYS_SYSCALL_H

