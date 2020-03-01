//
// Created by danim on 01/03/2020.
//

#include "Util.h"


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

template<char delimiter>
class WordDelimitedBy : public string
{};

vector<string> Split(string& text)
{
    vector<string> results;

    auto pos  = 0;
    auto newpos = 0;
    while  (newpos != string::npos) {
        newpos = text.find_first_of(',', pos);
        if (newpos != string::npos) {
            results.push_back(text.substr(pos, newpos - pos));
            pos = newpos + 1;
        } else {
            results.push_back(text.substr(pos));
        }
    }

    return results;
}