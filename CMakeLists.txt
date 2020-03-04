cmake_minimum_required(VERSION 3.10)
project(TotalTagMqttCpp VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(TotalTagMqttCpp main.cpp TagInfoCache.cpp TagInfoCache.h MqttClient.cpp MqttClient.h MessageParser.cpp MessageParser.h TagInfo.h EventManager.cpp EventManager.h TotalTagSender.cpp TotalTagSender.h Config.h Util.h Util.cpp TotalTagSenderCache.h TotalTagSenderCache.cpp)

configure_file(VersionConfig.h.in VersionConfig.h)
target_include_directories(TotalTagMqttCpp PUBLIC "${PROJECT_BINARY_DIR}")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(TotalTagMqttCpp Threads::Threads paho-mqtt3c)

add_subdirectory(cpr)
include_directories(${CPR_INCLUDE_DIRS})
target_link_libraries(TotalTagMqttCpp ${CPR_LIBRARIES})
