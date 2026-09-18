# Monte Carlo Portfolio Simulator

A C++ Monte Carlo simulation tool that estimates the probability of reaching a financial goal (e.g., retirement) given a portfolio, monthly contributions, and historical market behavior.

---

## What It Does

This simulator answers the question:

> "If I invest this way, what are my actual chances of reaching my financial goal?"

It takes your current portfolio, monthly contributions, time horizon, and financial goal — then runs thousands of simulated market scenarios to produce a probability of success.

---

## Features

- **Historical Statistics** — Calculates annualized return (μ) and volatility (σ) from daily closing prices
- **Geometric Brownian Motion** — Simulates realistic stock price paths using GBM
- **Monte Carlo Engine** — Runs 10,000+ independent simulations
- **Monthly Contributions** — Adds contributions along each simulated path
- **Result Analysis** — Computes probability of success, median, 5th and 95th percentiles
- **Random Number Generation** — Uses Mersenne Twister with normal distribution (N(0,1))

---

## Project Structure
