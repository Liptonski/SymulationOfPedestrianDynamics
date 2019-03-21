//
// Created by michal on 03.09.18.
//

#ifndef SYMULACJA_RUCHU_PIESZYCH_STATICFIELD_H
#define SYMULACJA_RUCHU_PIESZYCH_STATICFIELD_H

#include "Reader.h"

class StaticField {
    std::vector<std::pair<int,int>> sources;

public:
    Reader r;
    StaticField(const char *file, const char* values);
    void upload();
    std::vector<std::pair<int,int>> spread(std::pair<int,int>);
    void fill();
    virtual ~StaticField(){};
};


#endif //SYMULACJA_RUCHU_PIESZYCH_STATICFIELD_H
