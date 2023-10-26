
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -g


PROJECT = WebsocketEagler
SOURCES = 
HEADERS = 

OUTPUT = $(PROJECT)

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(OUTPUT)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJECTS) $(OUTPUT)
