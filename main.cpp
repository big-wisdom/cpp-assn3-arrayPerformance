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

SourceArray sorted()
{
    SourceArray source = generateArray();
    std::sort(source.begin(), source.end());
    return source;
}

SourceArray reversed()
{
    SourceArray source = sorted();
    std::reverse(source.begin(), source.end());
    return source;
}

int main() {
    SourceArray source = generateArray();
    evaluateRawArray(source, sorted(), reversed(), source, source);
    return 0;
}
