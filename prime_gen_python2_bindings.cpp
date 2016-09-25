#include <vector>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

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

/**
 * Generate the python bindings for this C++ function
 */
PYBIND11_PLUGIN(primes_py2) {
    py::module m("example", "Generating primes in c++ with python bindings using pybind11");

    m.def("generate_primes", &generate_primes, "A function which generates a list of primes. The length of this list is specified by the user");

    return m.ptr();
}
