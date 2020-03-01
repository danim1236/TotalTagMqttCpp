cmake_minimum_required(VERSION 3.15)
project(TotalTagMqttDocker)

set(CMAKE_CXX_STANDARD 14)

add_executable(TotalTagMqttDocker main.cpp MessageCache.cpp MessageCache.h MqttClient.cpp MqttClient.h MessageParser.cpp MessageParser.h TagInfo.h EventManager.cpp EventManager.h TotalTagSender.cpp TotalTagSender.h)