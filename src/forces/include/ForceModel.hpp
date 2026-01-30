#pragma once
#include <Eigen/Dense>

class ForceModel {
   private:
    double G;

   public:
    ForceModel();

    void addForce();
    void buildModel();
    Eigen::VectorXd ODE(double t, Eigen::VectorXd x);

    ~ForceModel();
};
