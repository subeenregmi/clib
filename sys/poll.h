/* Copyright (C) 2024
 *
 * Author: Subeen Regmi <subeenregmi123@gmail.com>
 * Date: 2024-02-07
 *
 * Structure of a poll and the events that it stores and the events that can be
 * stored in a poll. 
 */
#ifndef CLIB_SYS_POLL_H
#define CLIB_SYS_POLL_H


#define POLL_NREAD                  0x1         // There is new data to be read on the fd
#define POLL_EXCEPTIONAL            0x2         // Exceptional condition on file descriptor
#define POLL_WRITE                  0x4         // Writing is now possible on fd 
#define POLL_SOCKET_CLOSE_CONN      0x2000      // Stream socket peer closed connection, or shutdown
                                                // writing half connection
#define POLL_ERROR                  0x8         // An error has occurred
#define POLL_HANG_UP                0x10        // In a stream socket, peer closed its end of the
                                                // channel
#define POLL_INVALID                0x20        // Invalid request, fd is not open

struct pollfd {
    int fd;
    short events;
    short revents;
};


#endif // CLIB_SYS_POLL_H
