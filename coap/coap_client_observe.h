

#ifndef _COAP_CLIENT_OBSERVE_H
#define _COAP_CLIENT_OBSERVE_H

//Dependencies
#include "core/net.h"
#include "coap/coap_client.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//CoAP client related functions
error_t coapClientProcessNotification(CoapClientRequest *request,
   const CoapMessage *response);

bool_t coapClientCheckSequenceNumber(CoapClientRequest *request,
   uint32_t v2, systime_t t2);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
