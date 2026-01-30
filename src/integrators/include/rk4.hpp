#pragma once
#include "Eigen/Dense"

class RK4 {
   private:
    double h;

   public:
    RK4(double step_size);
    ~RK4();

    template <typename F>
    Eigen::VectorXd step(const Eigen::VectorXd& x, double t, F f) {
        Eigen::VectorXd k1 = f(t, x);
        Eigen::VectorXd k2 = f(t + h / 2, x + (h / 2) * k1);
        Eigen::VectorXd k3 = f(t + h / 2, x + (h / 2) * k2);
        Eigen::VectorXd k4 = f(t + h, x + h * k3);
        return x + (h / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
    }
};
