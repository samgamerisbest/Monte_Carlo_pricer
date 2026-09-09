#include "stats.hpp"
#include <cmath>

stockstats calculatestats(const std::vector<double>& prices)
{
    stockstats result;
    
    int n =  prices.size();
    double daily_return = 0;
    double sum = 0;

    for(int i = 0; i<prices.size();i++)
    {
        daily_return += log((prices[i+1])/(prices[i]));
        sum += daily_return;
    }

    result.mu = 252* (sum/n);
   



}
