#pragma once
#include <string>
#include <vector>
struct stock
{
    std::string name;
    int shares;
    double  price;
};

struct stockstats
{
    double sigma;  // volatily
    double mu;     // mean
};
struct simulationresult
{
    double prob; //probability of success
    double median; // median value of the simulations
    double p5; //5th percentile value
    double p95; //95th percentile value
    std::vector<double>  all_results; 

};
