#include <iostream>
#include "Random.hpp"

int main() {
    RandomGenerator rng;
    
    
    for (int i = 0; i < 10; i++) {
        std::cout << rng.next_normal() << std::endl;
    }
    
    return 0;
}