//
// Created by danim on 01/03/2020.
//

#ifndef TOTALTAGMQTTDOCKER_TOTALTAGSENDER_H
#define TOTALTAGMQTTDOCKER_TOTALTAGSENDER_H

#include <string>
#include <vector>
#include "TagInfo.h"

using namespace std;

class TotalTagSender
{
public:
    TotalTagSender(string& url, int readerId);
    ~TotalTagSender();

    void AddReadTag(TagInfo& tagInfo);
    void AddReadTag(vector<TagInfo>& tagInfos);

private:
    string _url;
    int _readerId;
};


#endif //TOTALTAGMQTTDOCKER_TOTALTAGSENDER_H
