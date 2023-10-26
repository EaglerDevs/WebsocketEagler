

#ifndef _DHCP_DEBUG_H
#define _DHCP_DEBUG_H

//Dependencies
#include "core/net.h"
#include "dhcp/dhcp_common.h"
#include "debug.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//Check current trace level
#if (DHCP_TRACE_LEVEL >= TRACE_LEVEL_DEBUG)
   error_t dhcpDumpMessage(const DhcpMessage *message, size_t length);
   error_t dhcpDumpMessageType(const DhcpOption *option);
   error_t dhcpDumpParamRequestList(const DhcpOption *option);
   error_t dhcpDumpBoolean(const DhcpOption *option);
   error_t dhcpDumpInt8(const DhcpOption *option);
   error_t dhcpDumpInt16(const DhcpOption *option);
   error_t dhcpDumpInt32(const DhcpOption *option);
   error_t dhcpDumpString(const DhcpOption *option);
   error_t dhcpDumpIpv4Addr(const DhcpOption *option);
   error_t dhcpDumpIpv4AddrList(const DhcpOption *option);
   error_t dhcpDumpRawData(const DhcpOption *option);
#else
   #define dhcpDumpMessage(message, length)
#endif

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
