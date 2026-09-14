#include "Random.hpp"

RandomGenerator::RandomGenerator()

   : gen(std::random_device{}()),
    dist(0.0, 1.0)
{

}


double RandomGenerator::next_normal()
{
    return dist(gen);
}

