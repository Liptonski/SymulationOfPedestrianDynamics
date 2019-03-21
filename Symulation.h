//
// Created by michal on 04.09.18.
//

#ifndef SYMULACJA_RUCHU_PIESZYCH_SYMULATION_H
#define SYMULACJA_RUCHU_PIESZYCH_SYMULATION_H

#include "StaticField.h"
#include <algorithm>
#include <random>

class RandomGen{
    std::random_device rd;
    int max;
    typedef std::mt19937 MyRng;
    MyRng rng;
    std::uniform_int_distribution<int> dice;
public:
    RandomGen(int m);
    int roll(){
        return dice(rng);
    }
};

class Symulation {
    StaticField s;
public:
    Symulation(const char *file, const char* values);
    virtual ~Symulation(){};
    void move();
    void turn(int number);
    void check();
};




#endif //SYMULACJA_RUCHU_PIESZYCH_SYMULATION_H
