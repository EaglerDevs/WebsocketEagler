

#ifndef _COAP_CLIENT_MISC_H
#define _COAP_CLIENT_MISC_H

//Dependencies
#include "core/net.h"
#include "coap/coap_client.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//CoAP client related functions
error_t coapClientProcessEvents(CoapClientContext *context, systime_t timeout);
error_t coapClientProcessRequestEvents(CoapClientRequest *request);

error_t coapClientChangeRequestState(CoapClientRequest *request,
   CoapRequestState newState);

error_t coapClientMatchResponse(const CoapClientRequest *request,
   const CoapMessage *response);

error_t coapClientProcessResponse(CoapClientRequest *request,
   const CoapMessage *response);

error_t coapClientRejectResponse(CoapClientContext *context,
   const CoapMessage *response);

error_t coapClientSendAck(CoapClientContext *context, uint16_t mid);
error_t coapClientSendReset(CoapClientContext *context, uint16_t mid);

void coapClientGenerateMessageId(CoapClientContext *context,
   CoapMessageHeader *header);

void coapClientGenerateToken(CoapClientContext *context,
   CoapMessageHeader *header);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
