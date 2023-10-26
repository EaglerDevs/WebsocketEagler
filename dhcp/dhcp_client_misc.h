

#ifndef _DHCP_CLIENT_MISC_H
#define _DHCP_CLIENT_MISC_H

//Dependencies
#include "core/net.h"
#include "dhcp/dhcp_client.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//Tick counter to handle periodic operations
extern systime_t dhcpClientTickCounter;

//DHCP client related functions
void dhcpClientTick(DhcpClientContext *context);
void dhcpClientLinkChangeEvent(DhcpClientContext *context);

error_t dhcpClientSendDiscover(DhcpClientContext *context);
error_t dhcpClientSendRequest(DhcpClientContext *context);
error_t dhcpClientSendDecline(DhcpClientContext *context);
error_t dhcpClientSendRelease(DhcpClientContext *context);

void dhcpClientProcessMessage(NetInterface *interface,
   const IpPseudoHeader *pseudoHeader, const UdpHeader *udpHeader,
   const NetBuffer *buffer, size_t offset, const NetRxAncillary *ancillary,
   void *param);

void dhcpClientParseOffer(DhcpClientContext *context,
   const DhcpMessage *message, size_t length);

void dhcpClientParseAck(DhcpClientContext *context,
   const DhcpMessage *message, size_t length);

void dhcpClientParseNak(DhcpClientContext *context,
   const DhcpMessage *message, size_t length);

void dhcpClientCheckTimeout(DhcpClientContext *context);

uint16_t dhcpClientComputeElapsedTime(DhcpClientContext *context);

void dhcpClientChangeState(DhcpClientContext *context,
   DhcpState newState, systime_t delay);

void dhcpClientResetConfig(DhcpClientContext *context);
void dhcpClientDumpConfig(DhcpClientContext *context);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
