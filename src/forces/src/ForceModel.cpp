#include "ForceModel.hpp"

#include <math.h>
#include <stdio.h>

#include <iostream>

#include "Constants.hpp"
#include "Eigen/Dense"

ForceModel::ForceModel() {
    printf("Constructor of simple attraction\n");
}

void ForceModel::addForce() {
    printf("\tAdding Force to the model\n");
}

void ForceModel::buildModel() {
    printf("\tBuilding model\n");
}

Eigen::VectorXd ForceModel::ODE(double t, Eigen::VectorXd x) {
    double mu = Constants::WGS84_EARTH_MU;

    Eigen::Vector3d r = x.head(3);
    Eigen::Vector3d v = x.tail(3);

    // std::cout << "r: \n" <<
    double r_norm = r.norm();

    Eigen::Vector3d a = -mu * r / pow(r_norm, 3);

    Eigen::VectorXd a_final(6);
    a_final << v(0), v(1), v(2), a(0), a(1), a(2);

    return a_final;
}

ForceModel::~ForceModel() {}
