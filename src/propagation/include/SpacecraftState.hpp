#pragma once

#include "Eigen/Dense"

class SpacecraftState {
   private:
    /* Current mass (kg) */
    double mass;

    /* Current cross section area relative to the velocity vector (m^2)*/
    double area;

    /* TODO: implement attitude functionality */
    // Eigen::Matrix3d inertia;
    // Eigen::Vector3d attitude;

    /* TODO: implement orbit */
    // Orbit::Osculating

    /* State vector 6x1 in m and m/s */
    Eigen::VectorXd stateVector;

   public:
    SpacecraftState(Eigen::VectorXd& sv, double& m, double& a);

    double getMass();
    double getArea();
    Eigen::VectorXd getStateVector();

    void setStateVector(Eigen::VectorXd newStateVector);

    ~SpacecraftState();
};
