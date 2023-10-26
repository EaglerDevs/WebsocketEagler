

#ifndef _ETHERNET_MISC_H
#define _ETHERNET_MISC_H

//Dependencies
#include "core/net.h"
#include "core/ethernet.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//Ethernet related constants
extern const uint8_t ethPadding[64];

//Ethernet related functions
error_t ethPadFrame(NetBuffer *buffer, size_t *length);

error_t ethEncodeVlanTag(NetBuffer *buffer, size_t *offset, uint16_t vlanId,
   int8_t vlanPcp, int8_t vlanDei, uint16_t type);

error_t ethDecodeVlanTag(const uint8_t *frame, size_t length, uint16_t *vlanId,
   uint16_t *type);

error_t ethCheckDestAddr(NetInterface *interface, const MacAddr *macAddr);
bool_t ethTrapIgmpPacket(EthHeader *header, uint8_t *data, size_t length);

void ethUpdateInStats(NetInterface *interface, const MacAddr *destMacAddr);

void ethUpdateOutStats(NetInterface *interface, const MacAddr *destMacAddr,
   size_t length);

void ethUpdateErrorStats(NetInterface *interface, error_t error);

uint32_t ethCalcCrc(const void *data, size_t length);
uint32_t ethCalcCrcEx(const NetBuffer *buffer, size_t offset, size_t length);

error_t ethCheckCrc(NetInterface *interface, const uint8_t *frame,
   size_t length);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
