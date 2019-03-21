//
// Created by michal on 21.08.18.
//

#include "Reader.h"

Reader::Reader(const char *file, const char* values) : current(0,0) {
    char buf[256];
    char c;
    std::ifstream val(values);
    if(!val.is_open()) printf("WYJATEK");
    while(!val.eof()){
        val.getline(buf, 256);
        s.push_back(new std::string(buf));
    }
    std::ifstream in(file);
    if(!in.is_open()) printf("WYJATEK");
    int z=1;
    while(in.get(c)){
        //tworzenie sciany
        if(c=='x') {
            board.emplace(current,Field(0, 'W', current, false, 0));
        }
        if(c==' ') board.emplace(current, Field(50, 'F', current, false,0));
        if(c=='*') {
            board.emplace(current, Field(50, 'D', current, false,0));
        }
        if(c=='$') {
            board.emplace(current, Field(50, 'S', current, false,0));
        }
        if(c=='!'){
            board.emplace(current, Field(50, 'F', current, true, z));
            begining_pedestrians.push_back(current);
            z++;
        }
        current.second++;
        if(c=='\n') {
            rows=current.second-1;
            current.second=0;
            current.first++;
        }
    }
}

Reader::~Reader() {
    for(int i=0; i<s.size(); i++){
        delete s[i];
    }
}

