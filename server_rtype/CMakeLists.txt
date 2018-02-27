cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY})

SET(CMAKE_CXX_STANDARD 11)

project(cpp_rtype)


set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories(include ../common/network/include)
include_directories(include ../common/tools)

add_executable(
		server_rtype	
		src/main.cpp
		src/Server.cpp
		src/Client.cpp
		src/ClientManager.cpp
		src/Player.cpp
		src/Game.cpp
		src/Room.cpp
		src/RoomManager.cpp
		src/PacketManager.cpp
		../common/network/include/ISocket.hpp
		../common/network/include/NetException.hpp
		../common/network/UnixSocket.cpp
		../common/network/Packet.cpp
		../common/network/include/UnixSocket.hpp
		../common/network/WindowsSocket.cpp
		../common/network/include/WindowsSocket.hpp
		include/rtype.h
		include/Entity.hpp
		include/Game.hpp
)

if(${UNIX})
  set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -std=c++0x -lpthread")
  set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} -ggdb -W -Wall -lpthread")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG -lpthread")
endif()


if(WIN32)
    add_definitions(/D _CRT_SECURE_NO_WARNINGS)
    add_definitions(/D NOMINMAX)
    add_definitions(/D WIN32_LEAN_AND_MEAN)
    set(GUI_TYPE WIN32)
endif(WIN32)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(server_rtype Threads::Threads)
