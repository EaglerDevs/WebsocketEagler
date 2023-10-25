 #ifndef _WEB_SOCKET_MISC_H
 #define _WEB_SOCKET_MISC_H
  
 //Dependencies
 #include "core/net.h"
 #include "web_socket/websocket.h"
  
 //C++ guard
 #ifdef __cplusplus
 extern "C" {
 #endif
  
  
 /**
  * @brief HTTP status code
  **/
  
 typedef struct
 {
    uint_t value;
    const char_t message[28];
 } WebSocketStatusCodeDesc;
  
  
 //WebSocket related functions
 void webSocketChangeState(WebSocket *webSocket, WebSocketState newState);
  
 error_t webSocketParseHandshake(WebSocket *webSocket);
 error_t webSocketParseRequestLine(WebSocket *webSocket, char_t *line);
 error_t webSocketParseStatusLine(WebSocket *webSocket, char_t *line);
 error_t webSocketParseHeaderField(WebSocket *webSocket, char_t *line);
  
 void webSocketParseConnectionField(WebSocket *webSocket, char_t *value);
  
 error_t webSocketFormatClientHandshake(WebSocket *webSocket, uint16_t serverPort);
 error_t webSocketFormatServerHandshake(WebSocket *webSocket);
  
 error_t webSocketFormatErrorResponse(WebSocket *webSocket,
    uint_t statusCode, const char_t *message);
  
 error_t webSocketVerifyClientHandshake(WebSocket *webSocket);
 error_t webSocketVerifyServerHandshake(WebSocket *webSocket);
  
 error_t webSocketGenerateClientKey(WebSocket *webSocket);
 error_t webSocketGenerateServerKey(WebSocket *webSocket);
  
 error_t webSocketVerifyClientKey(WebSocket *webSocket);
 error_t webSocketVerifyServerKey(WebSocket *webSocket);
  
 bool_t webSocketCheckStatusCode(uint16_t statusCode);
  
 error_t webSocketDecodePercentEncodedString(const char_t *input,
    char_t *output, size_t outputSize);
  
 bool_t webSocketCheckUtf8Stream(WebSocketUtf8Context *context,
    const uint8_t *data, size_t length, size_t remaining);
  
 //C++ guard
 #ifdef __cplusplus
 }
 #endif
  
 #endif
