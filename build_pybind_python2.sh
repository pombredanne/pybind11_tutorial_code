#!/bin/bash
g++ -O3 -fPIC -shared -std=c++11 -I /home/janis/code_snippets/prime_gen/pybind11-1.8.1/include `python-config --cflags --ldflags` prime_gen_python2_bindings.cpp -o primes_py2.so
