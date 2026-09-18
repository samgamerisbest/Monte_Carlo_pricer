#include "simulations.hpp"
#include <cmath>
#include "types.hpp"
#include "stats.hpp"

 PortfolioSimulator::PortfolioSimulator(
    const std::vector<stock>& portfolio,
    double monthly_contribution,
    int years,
    int num_simulations,
    const std::vector<stockstats>& stats,
    double goal
) : portfolio_(portfolio),
    monthly_contribution_(monthly_contribution),
    years_(years),
    num_simulations_(num_simulations),
    stats_(stats),
    goal_(goal)
{
}

simulationresult PortfolioSimulator::run(double goal)
{
    double mu = stats_[0].mu;
    double sigma = stats_[0].sigma;
    RandomGenerator rng;
    double dt = 1.0 / 252.0;
    simulationresult result;

    double initial_portfoliovalue = 0.0;
    for (const stock& s : portfolio_) {
        initial_portfoliovalue += s.shares * s.price;
    }

    double shares = portfolio_[0].shares;

    for (int i = 0; i < num_simulations_; i++) {
        double intistock = portfolio_[0].price;
        double portfolio_value = shares * intistock;
        int temp = 0;

        for (int day = 0; day < years_ * 252; day++) {
            double Z = rng.next_normal();
            intistock = intistock * std::exp((mu - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * Z);
            portfolio_value = shares * intistock;

            temp++;
            if (temp == 21) {
                temp = 0;
                portfolio_value += monthly_contribution_;
            }
        }

        result.all_results.push_back(portfolio_value);
    }

    return result;
}