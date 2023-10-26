

#ifndef _COAP_SERVER_MISC_H
#define _COAP_SERVER_MISC_H

//Dependencies
#include "core/net.h"
#include "coap/coap_server.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//CoAP server related functions
void coapServerTick(CoapServerContext *context);

error_t coapServerProcessRequest(CoapServerContext *context,
   const uint8_t *data, size_t length);

error_t coapServerRejectRequest(CoapServerContext *context);

error_t coapServerInitResponse(CoapServerContext *context);

error_t coapServerSendResponse(CoapServerContext *context,
   const void *data, size_t length);

error_t coapServerFormatReset(CoapServerContext *context, uint16_t mid);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
