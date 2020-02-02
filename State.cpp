//
// Created by yuvalshechter on 29/01/2020.
//

#include "State.h"

State::State(string indexes1, double cost1){
  this->cost = cost1;
  this->fatherVertex = NULL;
  this->indexes = indexes1;

}
State * State::getFatherVertex() {
  return this->fatherVertex;
}

double State::getCostVertex() {
  return this->cost;
}
void State::setFatherVertex(State *fatherVertex) {
  this->fatherVertex = fatherVertex;
}

void State::setCost(double cost) {
  this->cost = cost;
}

//this is function the hold the indexes of the vertex in the vertexMap
void State::setIndex(string indexes) {
  this->indexes = indexes;
}

State::~State(){}
