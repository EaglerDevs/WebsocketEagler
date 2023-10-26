
#ifndef _UDP_H
#define _UDP_H

//Dependencies
#include "core/net.h"
#include "core/tcp.h"

//UDP support
#ifndef UDP_SUPPORT
   #define UDP_SUPPORT ENABLED
#elif (UDP_SUPPORT != ENABLED && UDP_SUPPORT != DISABLED)
   #error UDP_SUPPORT parameter is not valid
#endif

//Maximum number of callback functions that can be registered
//to process incoming UDP datagrams
#ifndef UDP_CALLBACK_TABLE_SIZE
   #define UDP_CALLBACK_TABLE_SIZE 10
#elif (UDP_CALLBACK_TABLE_SIZE < 1)
   #error UDP_CALLBACK_TABLE_SIZE parameter is not valid
#endif

//Receive queue depth for connectionless sockets
#ifndef UDP_RX_QUEUE_SIZE
   #define UDP_RX_QUEUE_SIZE 4
#elif (UDP_RX_QUEUE_SIZE < 1)
   #error UDP_RX_QUEUE_SIZE parameter is not valid
#endif

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif


//CodeWarrior or Win32 compiler?
#if defined(__CWCC__) || defined(_WIN32)
   #pragma pack(push, 1)
#endif


/**
 * @brief UDP header
 **/

typedef __packed_struct
{
   uint16_t srcPort;  //0-1
   uint16_t destPort; //2-3
   uint16_t length;   //4-5
   uint16_t checksum; //6-7
   uint8_t data[];    //8
} UdpHeader;


//CodeWarrior or Win32 compiler?
#if defined(__CWCC__) || defined(_WIN32)
   #pragma pack(pop)
#endif


/**
 * @brief UDP receive callback
 **/

typedef void (*UdpRxCallback)(NetInterface *interface,
   const IpPseudoHeader *pseudoHeader, const UdpHeader *header,
   const NetBuffer *buffer, size_t offset, const NetRxAncillary *ancillary,
   void *param);


/**
 * @brief UDP receive callback entry
 **/

typedef struct
{
   NetInterface *interface;
   uint16_t port;
   UdpRxCallback callback;
   void *param;
} UdpRxCallbackEntry;


//Global variables
extern UdpRxCallbackEntry udpCallbackTable[UDP_CALLBACK_TABLE_SIZE];

//UDP related functions
error_t udpInit(void);
uint16_t udpGetDynamicPort(void);

error_t udpProcessDatagram(NetInterface *interface,
   const IpPseudoHeader *pseudoHeader, const NetBuffer *buffer, size_t offset,
   const NetRxAncillary *ancillary);

error_t udpSendDatagram(Socket *socket, const SocketMsg *message, uint_t flags);

error_t udpSendBuffer(NetInterface *interface, const IpAddr *srcIpAddr,
   uint16_t srcPort, const IpAddr *destIpAddr, uint16_t destPort,
   NetBuffer *buffer, size_t offset, NetTxAncillary *ancillary);

error_t udpReceiveDatagram(Socket *socket, SocketMsg *message, uint_t flags);

NetBuffer *udpAllocBuffer(size_t length, size_t *offset);

void udpUpdateEvents(Socket *socket);

error_t udpAttachRxCallback(NetInterface *interface, uint16_t port,
   UdpRxCallback callback, void *param);

error_t udpDetachRxCallback(NetInterface *interface, uint16_t port);

error_t udpInvokeRxCallback(NetInterface *interface,
   const IpPseudoHeader *pseudoHeader, const UdpHeader *header,
   const NetBuffer *buffer, size_t offset, const NetRxAncillary *ancillary);

void udpDumpHeader(const UdpHeader *datagram);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
