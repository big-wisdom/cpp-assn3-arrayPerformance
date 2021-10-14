#include <iostream>
#include <random>
#include "sortutils.hpp"

SourceArray generateArray()
{
    std::default_random_engine engine{0u};
    std::uniform_int_distribution<> dist{-10000000, 10000000};

    SourceArray array;
    std::generate(array.begin(), array.end(), [&] { return dist(engine); });
    return array;
}

int main() {
    SourceArray source = generateArray();
    std::cout << source.size() << std::endl;
    return 0;
}
