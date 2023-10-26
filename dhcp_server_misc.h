

#ifndef _DHCP_SERVER_MISC_H
#define _DHCP_SERVER_MISC_H

//Dependencies
#include "core/net.h"
#include "dhcp/dhcp_server.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//Tick counter to handle periodic operations
extern systime_t dhcpServerTickCounter;

//DHCP server related functions
void dhcpServerTick(DhcpServerContext *context);

void dhcpServerProcessMessage(NetInterface *interface,
   const IpPseudoHeader *pseudoHeader, const UdpHeader *udpHeader,
   const NetBuffer *buffer, size_t offset, const NetRxAncillary *ancillary,
   void *param);

void dhcpServerParseDiscover(DhcpServerContext *context,
   const DhcpMessage *message, size_t length);

void dhcpServerParseRequest(DhcpServerContext *context,
   const DhcpMessage *message, size_t length);

void dhcpServerParseDecline(DhcpServerContext *context,
   const DhcpMessage *message, size_t length);

void dhcpServerParseRelease(DhcpServerContext *context,
   const DhcpMessage *message, size_t length);

void dhcpServerParseInform(DhcpServerContext *context,
   const DhcpMessage *message, size_t length);

error_t dhcpServerSendReply(DhcpServerContext *context, uint8_t type,
   Ipv4Addr yourIpAddr, const DhcpMessage *request, size_t requestLen);

DhcpServerBinding *dhcpServerCreateBinding(DhcpServerContext *context);

DhcpServerBinding *dhcpServerFindBindingByMacAddr(DhcpServerContext *context,
   const MacAddr *macAddr);

DhcpServerBinding *dhcpServerFindBindingByIpAddr(DhcpServerContext *context,
   Ipv4Addr ipAddr);

error_t dhcpServerGetNextIpAddr(DhcpServerContext *context, Ipv4Addr *ipAddr);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
