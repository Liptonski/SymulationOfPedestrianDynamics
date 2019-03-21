//
// Created by michal on 21.08.18.
//

#ifndef SYMULACJA_RUCHU_PIESZYCH_READER_H
#define SYMULACJA_RUCHU_PIESZYCH_READER_H
#include "Field.h"
#include <fstream>

class Reader {
public:
    Reader(const char* file, const char* values);
    virtual ~Reader();
    //void save () const;
    std::pair<int,int> current;
    std::map<std::pair<int,int>,Field> board;
    std::vector<std::pair<int,int>> begining_pedestrians;
    std::vector<std::string*> s;
    int rows;
};


#endif //SYMULACJA_RUCHU_PIESZYCH_READER_H
