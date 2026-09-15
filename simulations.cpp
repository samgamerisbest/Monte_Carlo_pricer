#include "simulations.hpp"
#include <cmath>
#include "types.hpp"
#include "stats.hpp"

PortfolioSimulator::PortfolioSimulator
(
                const std::vector<stock>& portfolio,  //  For portfolio
                double monthly_contribution,          //  For monthly_contribution
                int years,                            //  For years
                int num_simulations,
                const std::vector<stockstats>& stats

)           : portfolio_(portfolio),
            monthly_contribution_(monthly_contribution),
            years_(years),
            num_simulations_(num_simulations),
            stats_(stats)
    {

    }

     simulationresult PortfolioSimulator::run()
     {


        double mu = stats_[0].mu;
        double sigma = stats_[0].sigma;
        RandomGenerator rng;
        double dt = 1.0/252.0;
        double GBM;
        simulationresult result;
        int temp = 0;


         for(const stock& s : portfolio_)
            double intial_portfoliovalue = s.shares * s.price;
           double intistock = portfolio_[0].price;

           
        for(int i = 0; i<num_simulations;i++)
            {   
                for(int day =0;day < years_*252;day++)
                {
                     double Z = rng.next_normal();
                     GBM = intistock * std::exp((mu - 0.5 * sigma*sigma) * dt + sigma *std::sqrt(dt) * Z);
                     intistock = GBM;      
                    while(temp < 21)
                    {
                        temp++;
                        if(temp == 21)
                            {
                                temp = 0;
                                intial_portfoliovalue += monthly_contribution;
                            }
                    }


                }
            }
             
      }
