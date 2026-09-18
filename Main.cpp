#include <iostream>
#include <vector>
#include "types.hpp"
#include "stats.hpp"
#include "simulations.hpp"
#include "analyzer.hpp"

int main() {
    // 1. Create portfolio
    std::vector<stock> portfolio = {
        {"AAPL", 100, 150.00}
    };
    
    // 2. Historical prices for AAPL
    std::vector<double> prices = {
    150.00, 150.12, 149.88, 150.25, 150.50, 150.38, 150.75, 151.00, 
    150.85, 151.12, 151.25, 151.00, 151.38, 151.50, 151.25, 151.62,
    151.75, 151.50, 151.88, 152.00
    };
    
    // 3. Calculate stats (mu and sigma)
    stockstats stats = calculatestats(prices);
    
    // 4. Create simulator
    double monthly_contribution = 1000.0;
    int years = 20;
    int num_simulations = 10000;
    double goal = 1000000.0;
    
    std::vector<stockstats> stats_vec = {stats};
    
    PortfolioSimulator sim(
        portfolio,
        monthly_contribution,
        years,
        num_simulations,
        stats_vec,
        goal
    );
    
   
    simulationresult result = sim.run(goal);
    
   
    result = analyzer::analyze(result.all_results, goal);
    std::cout << "Mu: " << stats.mu << std::endl;
    std::cout << "Sigma: " << stats.sigma << std::endl;
    
   
    std::cout << "=== Monte Carlo Simulation Results ===" << std::endl;
    std::cout << "Goal: $" << goal << std::endl;
    std::cout << "Probability of success: " << result.prob * 100 << "%" << std::endl;
    std::cout << "Median final value: $" << result.median << std::endl;
    std::cout << "5th percentile: $" << result.p5 << std::endl;
    std::cout << "95th percentile: $" << result.p95 << std::endl;
    
    return 0;
}