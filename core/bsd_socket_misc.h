
#ifndef _BSD_SOCKET_MISC_H
#define _BSD_SOCKET_MISC_H

//Dependencies
#include "core/net.h"
#include "core/bsd_socket.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//BSD socket related functions
void socketSetErrnoCode(Socket *socket, uint_t errnoCode);
void socketTranslateErrorCode(Socket *socket, error_t errorCode);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
