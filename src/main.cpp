#include <stdio.h>

#include <iostream>

#include "AbsoluteDate.hpp"
#include "Constants.hpp"
#include "Eigen/Dense"
#include "ForceModel.hpp"
#include "SpacecraftState.hpp"
#include "rk4.hpp"

int main() {
    /* Definition of Integrator */
    RK4 rk4(1.0);

    /* Definition of force Model
        Here is just a default ODE
    */
    ForceModel forceModel;

    // AbsoluteDate date(2025, 1, 1, 1, 1, 1.9);
    // std::cout << date.getJulianDate() << std::endl;

    AbsoluteDate date1(1996, 10, 26, 14, 20, 0.0, TimeSystem::UTC);
    std::cout << date1.getJulianDate() << std::endl;
    std::cout << date1.toString() << "\n";

    



    // AbsoluteDate date2(2025, 1, 1, 1, 1, 1.0);
    // std::cout << date2.getJulianDate() << std::endl;

    /* Initial state vector */
    Eigen::VectorXd x(6), temp_x(6);
    x << 7.47012265e+04, -7.23011339e+06, 4.30187218e+05, 6.91894434e+03, -1.26917557e+02,
        -2.47200977e+03;
    double t = 123.0;

    double mass = 10.0;
    double area = 19.0;
    SpacecraftState state(x, mass, area);

    /* Integration Loop */
    for (int i = 0; i < 2; i++) {
        Eigen::VectorXd x_next = rk4.step(
            x, t, [&](double tt, const Eigen::VectorXd& xx) { return forceModel.ODE(tt, xx); });
        x = x_next;

        std::cout << x(0) << "\t" << x(1) << "\t" << x(2) << "\n";
    }

    return 0;
}