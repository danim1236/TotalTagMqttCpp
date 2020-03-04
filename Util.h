//
// Created by danim on 01/03/2020.
//

#ifndef TOTALTAGMQTTDOCKER_UTIL_H
#define TOTALTAGMQTTDOCKER_UTIL_H


#include <string>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

string trim(const string& str);

vector<string> Split(string& text);

int msleep(long msec);


#endif //TOTALTAGMQTTDOCKER_UTIL_H
