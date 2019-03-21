//
// Created by michal on 24.08.18.
//

#include "Field.h"

Field::Field(int f, char t, std::pair<int,int> co, bool is, int ped_id) : static_field(f), type(t), coord(co), pedestrian(is), id(ped_id) {
    neighbours.emplace_back(std::pair<int,int>(coord.first-1, coord.second-1));
    neighbours.emplace_back(std::pair<int,int>(coord.first-1, coord.second));
    neighbours.emplace_back(std::pair<int,int>(coord.first-1, coord.second+1));
    neighbours.emplace_back(std::pair<int,int>(coord.first, coord.second-1));
    neighbours.emplace_back(std::pair<int,int>(coord.first, coord.second+1));
    neighbours.emplace_back(std::pair<int,int>(coord.first+1, coord.second-1));
    neighbours.emplace_back(std::pair<int,int>(coord.first+1, coord.second));
    neighbours.emplace_back(std::pair<int,int>(coord.first+1, coord.second+1));
}

Field::~Field(){}

