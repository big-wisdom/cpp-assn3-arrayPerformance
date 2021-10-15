#include <thread>
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

SourceArray rotated()
{
    SourceArray source = sorted();
    std::rotate(source.begin(), source.begin() + 1, source.end());
    return source;
}

int main() {
    SourceArray source = generateArray();
    SourceArray op = generateArray();
    organPipeStdArray(op);

    std::cout << "--- Raw Array Performance ---" << std::endl;
    evaluateRawArray(source, sorted(), reversed(), op, rotated());
    std::cout << std::endl;

    std::cout << "--- std::array Performance ---" << std::endl;
    evaluateStdArray(source, sorted(), reversed(), op, rotated());
    std::cout << std::endl;

    std::cout << "--- std::vector Performace ---" << std::endl;
    evaluateStdVector(source, sorted(), reversed(), op, rotated());
    std::cout << std::endl;
    return 0;
}
