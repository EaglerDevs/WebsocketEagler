

#ifndef _NET_MISC_H
#define _NET_MISC_H

//Forward declaration of NetTxAncillary structure
struct _NetTxAncillary;
#define NetTxAncillary struct _NetTxAncillary

//Forward declaration of NetRxAncillary structure
struct _NetRxAncillary;
#define NetRxAncillary struct _NetRxAncillary

//Dependencies
#include "core/net.h"
#include "core/ethernet.h"
#include "core/ip.h"

//Get a given bit of the PRNG internal state
#define NET_RAND_GET_BIT(s, n) ((s[(n - 1) / 8] >> ((n - 1) % 8)) & 1)

//Set a given bit of the PRNG internal state
#define NET_RAND_STATE_SET_BIT(s, n, v) s[(n - 1) / 8] = \
   (s[(n - 1) / 8] & ~(1 << ((n - 1) % 8))) | (v) << ((n - 1) % 8)

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Link change callback
 **/

typedef void (*NetLinkChangeCallback)(NetInterface *interface,
   bool_t linkState, void *param);


/**
 * @brief Link change callback entry
 **/

typedef struct
{
   NetInterface *interface;
   NetLinkChangeCallback callback;
   void *param;
} NetLinkChangeCallbackEntry;


/**
 * @brief Timer callback
 **/

typedef void (*NetTimerCallback)(void *param);


/**
 * @brief Timer callback entry
 **/

typedef struct
{
   systime_t timerValue;
   systime_t timerPeriod;
   NetTimerCallback callback;
   void *param;
} NetTimerCallbackEntry;


/**
 * @brief Timestamp
 **/

typedef struct
{
   uint32_t s;
   uint32_t ns;
} NetTimestamp;


/**
 * @brief Additional options passed to the stack (TX path)
 **/

struct _NetTxAncillary
{
   uint8_t ttl;         ///<Time-to-live value
   uint8_t tos;         ///<Type-of-service value
   bool_t dontRoute;    ///<Do not send the packet via a router
   bool_t routerAlert;  ///<Add an IP Router Alert option
#if (ETH_SUPPORT == ENABLED)
   MacAddr srcMacAddr;  ///<Source MAC address
   MacAddr destMacAddr; ///<Destination MAC address
#endif
#if (ETH_VLAN_SUPPORT == ENABLED)
   int8_t vlanPcp;      ///<VLAN priority (802.1Q)
   int8_t vlanDei;      ///<Drop eligible indicator
#endif
#if (ETH_VMAN_SUPPORT == ENABLED)
   int8_t vmanPcp;      ///<VMAN priority (802.1ad)
   int8_t vmanDei;      ///<Drop eligible indicator
#endif
#if (ETH_PORT_TAGGING_SUPPORT == ENABLED)
   uint8_t port;        ///<Egress port identifier
   uint32_t ports;      ///<Egress port map
   bool_t override;     ///<Override port state
#endif
#if (ETH_TIMESTAMP_SUPPORT == ENABLED)
   int32_t timestampId; ///<Unique identifier for hardware time stamping
#endif
};


/**
 * @brief Additional options passed to the stack (RX path)
 **/

struct _NetRxAncillary
{
   uint8_t ttl;            ///<Time-to-live value
   uint8_t tos;            ///<Type-of-service value
#if (ETH_SUPPORT == ENABLED)
   MacAddr srcMacAddr;     ///<Source MAC address
   MacAddr destMacAddr;    ///<Destination MAC address
   uint16_t ethType;       ///<Ethernet type field
#endif
#if (ETH_PORT_TAGGING_SUPPORT == ENABLED)
   uint8_t port;           ///<Ingress port identifier
#endif
#if (ETH_TIMESTAMP_SUPPORT == ENABLED)
   NetTimestamp timestamp; ///<Captured time stamp
#endif
};


/**
 * @brief Timer
 **/

typedef struct
{
   bool_t running;
   systime_t startTime;
   systime_t interval;
} NetTimer;


/**
 * @brief Pseudo-random number generator state
 **/

typedef struct
{
   uint16_t counter;
   uint8_t s[36];
} NetRandState;


//Global constants
extern const NetTxAncillary NET_DEFAULT_TX_ANCILLARY;
extern const NetRxAncillary NET_DEFAULT_RX_ANCILLARY;

//TCP/IP stack related functions
error_t netAttachLinkChangeCallback(NetInterface *interface,
   NetLinkChangeCallback callback, void *param);

error_t netDetachLinkChangeCallback(NetInterface *interface,
   NetLinkChangeCallback callback, void *param);

void netProcessLinkChange(NetInterface *interface);

error_t netAttachTimerCallback(systime_t period, NetTimerCallback callback,
   void *param);

error_t netDetachTimerCallback(NetTimerCallback callback, void *param);

void netTick(void);

void netStartTimer(NetTimer *timer, systime_t interval);
void netStopTimer(NetTimer *timer);
bool_t netTimerRunning(NetTimer *timer);
bool_t netTimerExpired(NetTimer *timer);

void netInitRand(void);
uint32_t netGenerateRand(void);
uint32_t netGenerateRandRange(uint32_t min, uint32_t max);
void netGenerateRandData(uint8_t *data, size_t length);
uint32_t netGenerateRandBit(NetRandState *state);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
