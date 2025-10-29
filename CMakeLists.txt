cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(tp02)

set(SOURCEFILES
        ${CMAKE_CURRENT_SOURCE_DIR}/source/menu.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/usuarios.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/menu.h
        ${CMAKE_CURRENT_SOURCE_DIR}/source/usuarios.h
        ${CMAKE_CURRENT_SOURCE_DIR}/source/juegos.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/juegos.h
        ${CMAKE_CURRENT_SOURCE_DIR}/source/utils.h
        ${CMAKE_CURRENT_SOURCE_DIR}/source/utils.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/stdpanel.h
        ${CMAKE_CURRENT_SOURCE_DIR}/source/stdpanel.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/personaje.h
        ${CMAKE_CURRENT_SOURCE_DIR}/source/personaje.cpp)
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp ${SOURCEFILES})
