
#ifndef _SOCKET_MISC_H
#define _SOCKET_MISC_H

//Dependencies
#include "core/net.h"
#include "core/socket.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//Socket related functions
Socket *socketAllocate(uint_t type, uint_t protocol);

void socketRegisterEvents(Socket *socket, OsEvent *event, uint_t eventMask);
void socketUnregisterEvents(Socket *socket);
uint_t socketGetEvents(Socket *socket);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
