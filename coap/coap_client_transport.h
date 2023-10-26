
#ifndef _COAP_CLIENT_TRANSPORT_H
#define _COAP_CLIENT_TRANSPORT_H

//Dependencies
#include "core/net.h"
#include "coap/coap_client.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//CoAP client related functions
error_t coapClientOpenConnection(CoapClientContext *context);

error_t coapClientEstablishConnection(CoapClientContext *context,
   const IpAddr *serverIpAddr, uint16_t serverPort);

error_t coapClientShutdownConnection(CoapClientContext *context);

void coapClientCloseConnection(CoapClientContext *context);

error_t coapClientSendDatagram(CoapClientContext *context,
   const void *data, size_t length);

error_t coapClientReceiveDatagram(CoapClientContext *context,
   void *data, size_t size, size_t *received);

error_t coapClientWaitForDatagram(CoapClientContext *context,
   systime_t timeout);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
