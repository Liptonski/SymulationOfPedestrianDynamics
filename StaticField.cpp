//
// Created by michal on 03.09.18.
//

#include "StaticField.h"

StaticField::StaticField(const char *file, const char* values) : r(file, values){}
void StaticField::upload() {
    for (int i = 0; i < r.s.size(); i++) {
        if (r.s[i]->c_str()[0] == '#') continue;
        else if (r.s[i]->c_str()[0] == 'D') {
            int x, y, val;
            sscanf(r.s[i]->c_str(), "D %d %d %d", &x, &y, &val);
            r.board[std::pair<int,int>(x-1,y-1)].static_field= val;
            sources.push_back(std::pair<int,int>(x-1,y-1));
        }
        else if (r.s[i]->c_str()[0] == 'S') {
            int xx, yy, vall;
            sscanf(r.s[i]->c_str(), "S %d %d %d", &xx, &yy, &vall);
            r.board[std::pair<int, int>(xx-1, yy-1)].static_field = vall;
            sources.push_back(std::pair<int, int>(xx-1, yy-1));
        }else if (r.s[i]->c_str()[0] == 'A') {
            int vval;
            sscanf(r.s[i]->c_str(), "A %d", &vval);
            std::map<std::pair<int, int>, Field>::iterator it = r.board.begin();
            for (it; it != r.board.end(); it++) {
                if ((*it).second.type == 'D' || (*it).second.type == 'S')
                    (*it).second.static_field = vval;
                sources.push_back(std::pair<int,int>((*it).first));
            }
        }
    }
}

std::vector<std::pair<int,int>> StaticField::spread(std::pair<int,int> source) {
    auto it =r.board[source];
    int temp = it.static_field;
    auto locals = it.neighbours;
    std::vector<std::pair<int,int>> rest;
    for(int j=0; j<locals.size(); j++){
        auto it2 = r.board.find(locals[j]);
        if((*it2).second.type =='F' && (*it2).second.static_field<temp-3){
            (*it2).second.static_field=temp-3;
            rest.push_back(locals[j]);
        }
    }
    return rest;
}

void StaticField::fill() {
    while(!sources.empty()){
        /*for(int j=sources.size()-1; j>=0; j--) {
            std::cout << "#" << j << " "<<sources[j].first << " : " << sources[j].second <<" ";
        }*/
        auto counter = spread(sources[sources.size()-1]);
        sources.pop_back();
        for(int i=0; i<counter.size(); i++){
            sources.push_back(counter[i]);
        }
        //std::cout<<std::endl;
    }
}

