#include "Eigen/Dense"
#include "PrintHello.hpp"
#include <iostream>

int main()
{
    Eigen::VectorXd x(3), temp_x(3);
    x = Eigen::VectorXd::LinSpaced(3, 0, 3);
    std::cout << x << "\n";

    printHello();
}
