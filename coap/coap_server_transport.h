

#ifndef _COAP_SERVER_TRANSPORT_H
#define _COAP_SERVER_TRANSPORT_H

//Dependencies
#include "core/net.h"
#include "coap/coap_server.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//CoAP server related functions
error_t coapServerAcceptSession(CoapServerContext *context,
   CoapDtlsSession *session, const IpAddr *remoteIpAddr, uint16_t remotePort);

error_t coapServerDemultiplexSession(CoapServerContext *context);

void coapServerDeleteSession(CoapDtlsSession *session);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
