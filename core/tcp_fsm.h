
#ifndef _TCP_FSM_H
#define _TCP_FSM_H

//Dependencies
#include "core/tcp.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//TCP FSM related functions
void tcpProcessSegment(NetInterface *interface,
   const IpPseudoHeader *pseudoHeader, const NetBuffer *buffer, size_t offset,
   const NetRxAncillary *ancillary);

void tcpStateClosed(NetInterface *interface, const IpPseudoHeader *pseudoHeader,
   const TcpHeader *segment, size_t length);

void tcpStateListen(Socket *socket, NetInterface *interface,
   const IpPseudoHeader *pseudoHeader, const TcpHeader *segment, size_t length);

void tcpStateSynSent(Socket *socket, const TcpHeader *segment, size_t length);

void tcpStateSynReceived(Socket *socket, const TcpHeader *segment,
   const NetBuffer *buffer, size_t offset, size_t length);

void tcpStateEstablished(Socket *socket, const TcpHeader *segment,
   const NetBuffer *buffer, size_t offset, size_t length);

void tcpStateCloseWait(Socket *socket, const TcpHeader *segment, size_t length);

void tcpStateLastAck(Socket *socket, const TcpHeader *segment, size_t length);

void tcpStateFinWait1(Socket *socket, const TcpHeader *segment,
   const NetBuffer *buffer, size_t offset, size_t length);

void tcpStateFinWait2(Socket *socket, const TcpHeader *segment,
   const NetBuffer *buffer, size_t offset, size_t length);

void tcpStateClosing(Socket *socket, const TcpHeader *segment, size_t length);

void tcpStateTimeWait(Socket *socket, const TcpHeader *segment, size_t length);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
