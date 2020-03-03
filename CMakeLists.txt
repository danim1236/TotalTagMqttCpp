cmake_minimum_required(VERSION 3.10)
project(TotalTagMqttDocker)

set(CMAKE_CXX_STANDARD 14)

add_executable(TotalTagMqttDocker main.cpp TagInfoCache.cpp TagInfoCache.h MqttClient.cpp MqttClient.h MessageParser.cpp MessageParser.h TagInfo.h EventManager.cpp EventManager.h TotalTagSender.cpp TotalTagSender.h Config.h Util.h Util.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(TotalTagMqttDocker Threads::Threads paho-mqtt3c)
