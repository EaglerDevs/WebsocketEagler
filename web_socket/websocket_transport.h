 #ifndef _WEB_SOCKET_TRANSPORT_H
 #define _WEB_SOCKET_TRANSPORT_H
  
 //Dependencies
 #include "core/net.h"
 #include "web_socket/websocket.h"
  
 //C++ guard
 #ifdef __cplusplus
 extern "C" {
 #endif
  
 //WebSocket related functions
 error_t webSocketOpenConnection(WebSocket *webSocket);
  
 error_t webSocketEstablishConnection(WebSocket *webSocket,
    const IpAddr *serverIpAddr, uint16_t serverPort);
  
 error_t webSocketShutdownConnection(WebSocket *webSocket);
 void webSocketCloseConnection(WebSocket *webSocket);
  
 error_t webSocketSendData(WebSocket *webSocket, const void *data,
    size_t length, size_t *written, uint_t flags);
  
 error_t webSocketReceiveData(WebSocket *webSocket, void *data,
    size_t size, size_t *received, uint_t flags);
  
 //C++ guard
 #ifdef __cplusplus
 }
 #endif
  
 #endif
