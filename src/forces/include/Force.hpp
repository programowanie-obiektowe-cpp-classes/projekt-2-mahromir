#pragma once

#include "Eigen/Dense"

class Force {
   public:
    std::string name;

    virtual Eigen::Vector3d acceleration();
    virtual void init();
};
