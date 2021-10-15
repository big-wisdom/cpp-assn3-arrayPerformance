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

std::array<int, 9> organPipe()
{
    // SourceArray source = sorted();
    std::array<int, 9> source = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //int n = source.size() /2;
    if((source.size() % 2) == 0){
        std::reverse_copy(source.begin(),source.begin()+ source.size()/2, source.begin()+(source.size()/2));
    } else {
        std::reverse_copy(source.begin(),source.begin()+ source.size()/2, source.begin()+(source.size()/2)+1);
    }

    return source;
}

int main() {
    SourceArray source = generateArray();
    std::array<int, 9> op = organPipe();
    for(int i : op)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    evaluateRawArray(source, sorted(), reversed(), source, source);
    return 0;
}
