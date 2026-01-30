
#include "rk4.hpp"

#include <math.h>
#include <stdio.h>

#include "Constants.hpp"
#include "Eigen/Dense"

RK4::RK4(double step_size) {
    h = step_size;
    printf("Init of RK4\n");

    Eigen::VectorXd step(const Eigen::VectorXd& x, double t,
                         const std::function<Eigen::VectorXd(double, const Eigen::VectorXd&)>& f);
}

RK4::~RK4() {}
