#pragma once
#include <vector>
#include "types.hpp"

class PortfolioSimulator
{
    public:
       
            PortfolioSimulator
               ( const std::vector<stock>& portfolio,  //  For portfolio
                double monthly_contribution,          //  For monthly_contribution
                int years,                            //  For years
                int num_simulations                   //  For num_simulations
               );
               
               simulationresult run();
       private:
      
                std::vector<stock> portfolio_;        
                double monthly_contribution_;         
                int years_;                           
                int num_simulations_;                 
};
