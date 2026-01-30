#include "SpacecraftState.hpp"

#include "Eigen/Dense"

SpacecraftState::SpacecraftState(Eigen::VectorXd& sv, double& m, double& a)
    : stateVector(sv), mass(m), area(a) {}

double SpacecraftState::getMass() {
    return mass;
}
double SpacecraftState::getArea() {
    return area;
}

Eigen::VectorXd SpacecraftState::getStateVector() {
    return stateVector;
}

void SpacecraftState::setStateVector(Eigen::VectorXd newStateVector) {
    stateVector = newStateVector;
}

SpacecraftState::~SpacecraftState() {};