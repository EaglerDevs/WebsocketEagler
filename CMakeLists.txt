cmake_minimum_required(VERSION 3.10)
project(WebSocketCEagler C)

set(CMAKE_C_STANDARD 99)

# Set source files for your project
set(SOURCES
    websocket.c
)

add_executable(WebSocketCExample ${SOURCES})
