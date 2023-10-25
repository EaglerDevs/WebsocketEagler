
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -g


PROJECT = WebsocketEagler
SOURCES = websocket.c
HEADERS = stdlib.h core/net.h web_socket/web_socket.h web_socket/web_socket_auth.h  web_socket/web_socket_frame.h web_socket/web_socket_transport.h web_socket/web_socket_misc.h str.h encoding/base64.h debug.h 
OBJECTS = $(SOURCES:.c=.o)

OUTPUT = $(PROJECT)

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(OUTPUT)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJECTS) $(OUTPUT)
