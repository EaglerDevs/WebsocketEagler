cmake_minimum_required(VERSION 3.10)
project(WebSocketCEagler C)

set(CMAKE_C_STANDARD 99)

set(SOURCES
    websocket.c
)

add_executable(WebSocketCEagler ${SOURCES})
