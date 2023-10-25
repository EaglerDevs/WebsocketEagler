#ifndef _WEB_SOCKET_AUTH_H
 #define _WEB_SOCKET_AUTH_H
  
 //Dependencies
 #include "core/net.h"
 #include "web_socket/web_socket.h"
  
 //C++ guard
 #ifdef __cplusplus
 extern "C" {
 #endif
  
 //WebSocket related functions
 error_t webSocketParseAuthenticateField(WebSocket *webSocket, char_t *value);
  
 size_t webSocketAddAuthorizationField(WebSocket *webSocket, char_t *output);
  
 void webSocketConvertArrayToHexString(const uint8_t *input,
    size_t inputLen, char_t *output);
  
 //C++ guard
 #ifdef __cplusplus
 }
 #endif
  
 #endif
