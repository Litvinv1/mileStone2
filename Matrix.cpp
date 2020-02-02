//
// Created by yuvalshechter on 29/01/2020.
//

#include <iostream>
#include "Matrix.h"
#include <algorithm>
using namespace std;

Matrix::Matrix(string buffer) {
    vector<string> mat_vec = parseLine(buffer);
    string goal_str = mat_vec[mat_vec.size()-2] + "," + mat_vec[mat_vec.size()-3];
    string initial_str = mat_vec[mat_vec.size()-5] + "," + mat_vec[mat_vec.size()-6];
    //this->initialState = new State(initial_str, )
    //this->goalState-> setIndex(goal_str);
    mat_vec.erase(mat_vec.end()-7, mat_vec.end());
    int row = 0;
    int column = 0;
    for(vector<string>::iterator it = mat_vec.begin(); it != mat_vec.end(); it++) {
        if (*it == "\n") {
            row++;
            column = 0;
            it++;
        }
        string cur_v = to_string(row) + "," + to_string(column);
        this->vertexMap[cur_v] = new State(cur_v, stod(*it));
        column++;
    }
    this->initialState = new State(initial_str, vertexMap[initial_str]->getCostVertex());
    this->goalState = new State(goal_str, vertexMap[goal_str]->getCostVertex());
}

State* Matrix::getInitialState() {
    return this->initialState;
}

State* Matrix::getGoalState() {
    return this->goalState;
}

vector<string> Matrix::parseLine(string buffer) {
    vector<string> vec;
    string delimiter = ",";
    //string delimeter2 = " ";
    size_t pos = 0;
    string vertexCost;
    //removing spaces
    buffer.erase(std::remove(buffer.begin(), buffer.end(), ' '), buffer.end());
    //creating the lexer vector
    for (int i = 0; i<buffer.length(); i++) {
      if (buffer[i] != ',') {
        vertexCost = buffer[i];
        vec.push_back(vertexCost);
      }
    }
    /*while ((pos = buffer.find(delimiter)) != std::string::npos) {

        vertexCost = buffer.substr(0, pos);
        vec.push_back(vertexCost);
        //cout << vertexCost << std::endl;
        buffer.erase(0, pos + delimiter.length());
    }
    vec.push_back(buffer);*/
    //cout << buffer << std::endl;
    return vec;
}

bool Matrix::isGoalState(State st) {
    return true;
}

unordered_map<string, State*>* Matrix:: get_vertex_map() {
    return &this->vertexMap;
};


