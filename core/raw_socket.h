

#ifndef _RAW_SOCKET_H
#define _RAW_SOCKET_H

//Dependencies
#include "core/net.h"
#include "core/ip.h"
#include "core/socket.h"

//Raw socket support
#ifndef RAW_SOCKET_SUPPORT
   #define RAW_SOCKET_SUPPORT DISABLED
#elif (RAW_SOCKET_SUPPORT != ENABLED && RAW_SOCKET_SUPPORT != DISABLED)
   #error RAW_SOCKET_SUPPORT parameter is not valid
#endif

//Receive queue depth for raw sockets
#ifndef RAW_SOCKET_RX_QUEUE_SIZE
   #define RAW_SOCKET_RX_QUEUE_SIZE 4
#elif (RAW_SOCKET_RX_QUEUE_SIZE < 1)
   #error RAW_SOCKET_RX_QUEUE_SIZE parameter is not valid
#endif

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//Raw socket related functions
error_t rawSocketProcessIpPacket(NetInterface *interface,
   const IpPseudoHeader *pseudoHeader, const NetBuffer *buffer, size_t offset,
   const NetRxAncillary *ancillary);

void rawSocketProcessEthPacket(NetInterface *interface, const uint8_t *data,
   size_t length, const NetRxAncillary *ancillary);

error_t rawSocketSendIpPacket(Socket *socket, const SocketMsg *message,
   uint_t flags);

error_t rawSocketSendEthPacket(Socket *socket, const SocketMsg *message,
   uint_t flags);

error_t rawSocketReceiveIpPacket(Socket *socket, SocketMsg *message,
   uint_t flags);

error_t rawSocketReceiveEthPacket(Socket *socket, SocketMsg *message,
   uint_t flags);

void rawSocketUpdateEvents(Socket *socket);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
