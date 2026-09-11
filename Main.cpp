#include "stats.hpp"
#include <iostream>

int main()
{
    std::vector<double> prices = {100, 101, 102, 101.5, 103};
    stockstats stats = calculatestats(prices);
    std::cout << "Mu: " << stats.mu << std::endl;
    std::cout << "Sigma: " << stats.sigma << std::endl;
}
