
#ifndef _DHCP_CLIENT_FSM_H
#define _DHCP_CLIENT_FSM_H

//Dependencies
#include "core/net.h"
#include "dhcp/dhcp_client.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//DHCP client related functions
void dhcpClientStateInit(DhcpClientContext *context);
void dhcpClientStateSelecting(DhcpClientContext *context);
void dhcpClientStateRequesting(DhcpClientContext *context);
void dhcpClientStateInitReboot(DhcpClientContext *context);
void dhcpClientStateRebooting(DhcpClientContext *context);
void dhcpClientStateProbing(DhcpClientContext *context);
void dhcpClientStateAnnouncing(DhcpClientContext *context);
void dhcpClientStateBound(DhcpClientContext *context);
void dhcpClientStateRenewing(DhcpClientContext *context);
void dhcpClientStateRebinding(DhcpClientContext *context);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
