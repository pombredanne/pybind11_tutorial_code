#include <iostream>
#include <vector>

/**
 * Generates the a sequence of prime numbers
 * @param how_many   how many primes to generate
 */
std::vector<int> generate_primes(unsigned int how_many){
    std::vector<int> primes;
    primes.reserve(how_many);
    primes.push_back(2); //2 is the first prime number
    unsigned int candidate = 3;
    bool potential_prime = true;
    while(primes.size() < how_many){
        potential_prime = true;
        for(unsigned int prime: primes){
            if(candidate % prime == 0){
                candidate += 2;
                potential_prime = false;
                break;
            }
        }
        if(potential_prime){
            primes.push_back(candidate);
        }
    }
    return primes;
}

int main(){
    std::vector<int> first_20_primes = generate_primes(20);
    for(int prime : first_20_primes){
        std::cout << prime << std::endl;
    }
    return 0;
}
