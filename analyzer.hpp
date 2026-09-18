#pragma once
#include "types.hpp"
#include <vector>

class analyzer

{
    public:
    static simulationresult analyze
    (
    std::vector<double>& all_results,
    double goal
    );
};  