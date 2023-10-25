#ifndef _WEB_SOCKET_FRAME_H
 #define _WEB_SOCKET_FRAME_H
  
 //Dependencies
 #include "core/net.h"
 #include "web_socket/web_socket.h"
  
 //C++ guard
 #ifdef __cplusplus
 extern "C" {
 #endif
  
 //WebSocket related functions
 error_t webSocketFormatFrameHeader(WebSocket *webSocket,
    bool_t fin, WebSocketFrameType type, size_t payloadLen);
  
 error_t webSocketParseFrameHeader(WebSocket *webSocket,
    const WebSocketFrame *frame, WebSocketFrameType *type);
  
 error_t webSocketFormatCloseFrame(WebSocket *webSocket);
  
 //C++ guard
 #ifdef __cplusplus
 }
 #endif
  
 #endif
