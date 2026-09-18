#pragma once
#include <vector>
#include "types.hpp"
#include "Random.hpp"


class PortfolioSimulator
{
    public:
       
            PortfolioSimulator
               ( 
                const std::vector<stock>& portfolio,  //  For portfolio
                double monthly_contribution,          //  For monthly_contribution
                int years,                            //  For years
                int num_simulations,             //  For num_simulations
                const std::vector<stockstats>& stats,
                double goal
               );
               
               simulationresult run(double goal);
       private:
      
                std::vector<stock> portfolio_;        
                double monthly_contribution_;         
                int years_;                           
                int num_simulations_;
                std::vector<stockstats> stats_;   
                double goal_;         
};
