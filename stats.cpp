#include "stats.hpp"
#include <cmath>

stockstats calculatestats(const std::vector<double>& prices)
{
     stockstats result;
    if(prices.size() < 2)
    {
        result.mu = 0;
        result.sigma = 0;
        return result;
    }
   
    int n =  prices.size()-1;
    double daily_return = 0;
    double sum = 0;
    double x;
    double sum2 = 0;
  

    for(int i = 0; i<n;i++)
    {
        daily_return = std::log((prices[i+1])/(prices[i]));
        sum += daily_return;
    }
    double mean = sum/n;
    result.mu = 252* (mean);

   for(int i = 0; i<n;i++)
    {
        daily_return = std::log((prices[i+1])/(prices[i]));
        x = daily_return - mean;
        x *= x;
        sum2 += x;

    } 

   result.sigma = std::sqrt(252) * std::sqrt(sum2/n);
   return result;

}
