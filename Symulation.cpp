//
// Created by michal on 04.09.18.
//

#include "Symulation.h"

Symulation::Symulation(const char *file, const char *values) : s(file, values) {
    s.upload();
    s.fill();
}

RandomGen::RandomGen(int m) : max(m), rng(rd()), dice(std::uniform_int_distribution<>(0, m)) {
    rng.seed(::time(nullptr));
}

void Symulation::move() {
    for(int i=0; i<s.r.begining_pedestrians.size(); i++) {
        auto it = s.r.board.find(s.r.begining_pedestrians[i]);
        std::map<std::pair<int, int>, Field>::iterator it2=it;
        std::vector<std::pair<int,int>> propabs;
        std::pair<int, int> help;
        int max = (*it).second.static_field;
        auto locals = (*it).second.neighbours;
        for (int j = 0; j < locals.size(); j++) {
            it2 = s.r.board.find(locals[j]);
            int dyn=(int)(*it2).second.dynamic_field.size()*2;
            for(int y=0; y<(*it2).second.dynamic_field.size(); y++){
                if((*it2).second.dynamic_field[y]==(*it).second.id){
                    dyn=0;
                }
            }
            if ((*it2).second.static_field + dyn>= max) {
                if ((*it2).second.static_field+ dyn > max)
                    propabs.clear();
                max = (*it2).second.static_field+dyn;
                propabs.push_back((*it2).second.coord);
            }
        }
        if(!propabs.empty()) {
            RandomGen g((int)propabs.size()-1);
            int randIndex=g.roll();
            help.first = propabs[randIndex].first;
            help.second = propabs[randIndex].second;
        }
        //std::cout << help.first << "__" << help.second <<std::endl;
        if(help!=(*it).second.coord)it2 = s.r.board.find(help);
        if (!((*it2).second.pedestrian || (*it2).second.type=='S')) {
            if((*it2).second.type=='D'){
                s.r.begining_pedestrians.erase(s.r.begining_pedestrians.begin()+i);
                (*it).second.dynamic_field.push_back((*it).second.id);
                (*it).second.pedestrian = false;
            }
            else {
                s.r.begining_pedestrians[i].first = help.first;
                s.r.begining_pedestrians[i].second = help.second;
                (*it).second.dynamic_field.push_back((*it).second.id);
                (*it).second.pedestrian = false;
                (*it2).second.pedestrian = true;
                (*it2).second.id=(*it).second.id;
                (*it).second.id=0;
            }
        }
    }
}

void Symulation::turn(int number) {
    for(int i=0; i<number;i++){
        std::map<std::pair<int, int>, Field>::iterator it = s.r.board.begin();
        int count=0;
        for (it; it != s.r.board.end(); it++) {
            if((*it).second.type=='W') std::cout << "x";
            if((*it).second.type=='F' && !(*it).second.pedestrian) std::cout << " ";
            if((*it).second.type=='F' && (*it).second.pedestrian) std::cout << "!";
            if((*it).second.type=='D') std::cout << "*";
            if((*it).second.type=='S') std::cout << "$";
            count++;
            if(count==s.r.rows){
                std::cout<<"\n";
                count=0;
            }
        }
        move();
    }
    std::ofstream out;
    out.open("result");
    std::map<std::pair<int, int>, Field>::iterator it = s.r.board.begin();
    int count=0;
    for (it; it != s.r.board.end(); it++) {
        if((*it).second.type=='W') out << "x";
        if((*it).second.type=='F' && !(*it).second.pedestrian) out << " ";
        if((*it).second.type=='F' && (*it).second.pedestrian) out << "!";
        if((*it).second.type=='D') out << "*";
        if((*it).second.type=='S') out << "$";
        count++;
        if(count==s.r.rows){
            out<<"\n";
            count=0;
        }
    }
}

void Symulation::check() {
    std::map<std::pair<int, int>, Field>::iterator it = s.r.board.begin();
    int count=0;
    for (it; it != s.r.board.end(); it++) {
        std::cout<< (*it).second.static_field +(*it).second.dynamic_field.size()*2 << " ";
        count++;
        if(count==s.r.rows){
            std::cout<<std::endl;
            count=0;
        }
    }
}