//
// Created by michal on 24.08.18.
//

#ifndef SYMULACJA_RUCHU_PIESZYCH_FIELD_H
#define SYMULACJA_RUCHU_PIESZYCH_FIELD_H

#include <iostream>
#include <utility>
#include <map>
#include <vector>

class Field {
public:
    bool pedestrian;
    char type;
    int static_field;
    int id;
    std::vector<int> dynamic_field;
    std::pair<int,int> coord;
    std::vector<std::pair<int,int>> neighbours;
    Field(){};
    virtual ~Field();
    Field(int f, char t, std::pair<int,int> co, bool is, int ped_id);
    //void move();
};

#endif //SYMULACJA_RUCHU_PIESZYCH_FIELD_H
