#pragma once
#include <random>

class RandomGenerator
{
    public:
            RandomGenerator();
            double next_normal();

    private:
            std::mt19937 gen;
            std::normal_distribution<double> dist;
};
