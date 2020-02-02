//
// Created by yuvalshechter on 29/01/2020.
//

#ifndef EX4_MATRIX_H
#define EX4_MATRIX_H


#include "Searchable.h"
#include <unordered_map>
#include <vector>
using namespace std;


class Matrix : public Searchable{
private:
    State *initialState;
    State *goalState;
    unordered_map<string, State*> vertexMap;

public:
    Matrix(string buffer);
    unordered_map<string, State*> creatVertexMap;
    vector<string>parseLine(string buffer);
    virtual State* getGoalState() ;
    virtual State* getInitialState() ;
    virtual bool isGoalState(State st);
    virtual unordered_map<string, State*>* get_vertex_map();


};


#endif //EX4_MATRIX_H
