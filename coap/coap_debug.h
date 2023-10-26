

#ifndef _COAP_DEBUG_H
#define _COAP_DEBUG_H

//Dependencies
#include "core/net.h"
#include "coap/coap_common.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Parameter value/name binding
 **/

typedef struct
{
   uint8_t value;
   const char_t *name;
} CoapParamName;


//CoAP related functions
error_t coapDumpMessage(const void *message, size_t length);
error_t coapDumpMessageHeader(const uint8_t *p, size_t length, size_t *consumed);
error_t coapDumpOptions(const uint8_t *p, size_t length, size_t *consumed);
error_t coapDumpOption(const CoapOption *option);

const char_t *coapGetParamName(uint_t value, const CoapParamName *paramList,
   size_t paramListLen);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
