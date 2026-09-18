#include <algorithm>
#include "analyzer.hpp"

simulationresult analyzer::analyze(std::vector<double>& all_results, double goal)
{
    simulationresult result;
    result.all_results = all_results;

    std::sort(result.all_results.begin(),result.all_results.end());

    int n = result.all_results.size();

    result.median = result.all_results[n/2];

    result.p5 = result.all_results[n*5/100];

    result.p95 = result.all_results[n*95/100];

    int successes = 0;
    for (double val : result.all_results) 
    {
        if (val >= goal) successes++;
    }
    result.prob = (double)successes / n;

    return result;


}
