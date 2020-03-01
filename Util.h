//
// Created by danim on 01/03/2020.
//

#ifndef TOTALTAGMQTTDOCKER_UTIL_H
#define TOTALTAGMQTTDOCKER_UTIL_H


#include <string>

using namespace std;

string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}



#endif //TOTALTAGMQTTDOCKER_UTIL_H
