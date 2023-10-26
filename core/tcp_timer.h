

#ifndef _TCP_TIMER_H
#define _TCP_TIMER_H

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//TCP timer related functions
void tcpTick(void);

void tcpCheckRetransmitTimer(Socket *socket);
void tcpCheckPersistTimer(Socket *socket);
void tcpCheckKeepAliveTimer(Socket *socket);
void tcpCheckOverrideTimer(Socket *socket);
void tcpCheckFinWait2Timer(Socket *socket);
void tcpCheckTimeWaitTimer(Socket *socket);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
