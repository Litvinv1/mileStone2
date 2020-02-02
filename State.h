//
// Created by yuvalshechter on 28/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H

#include <string>

using  namespace std;

//state class is when looking at a single vertex!
class State{
private:
    //string currentState;
    State *fatherVertex;
    double cost;
    string indexes;

public:
    State(string indexes1, double cost1);
    ~State();
    State *getFatherVertex();
    string getIndexVertex();
    double getCostVertex();
    void setFatherVertex(State *fatherVertex);
    void setcurrentState(string currentState);
    void setCost(double cost);
    void setIndex(string indexes);
};

#endif //EX4_STATE_H
