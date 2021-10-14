#include <iostream>
#include <algorithm>
#include <chrono>
#include "sortutils.hpp"

void initializeRawArrayFromStdArray(const SourceArray& source, int dest[]){
    std::copy(source.begin(), source.end(), dest);
}

void organPipeStdArray(SourceArray& data){
    std::cout << "organ pipe" << std::endl;
    std::cout << data.size() << std::endl;
}

void timeRawArray(SourceArray sa)
{
    std::chrono::duration<double> totalTime = std::chrono::steady_clock::duration::zero();
    for(int i=0; i < HOW_MANY_TIMES; i++)
    {
        int raw[250000];
        initializeRawArrayFromStdArray(sa, raw);
        auto start = std::chrono::steady_clock::now(); // start timer
        std::sort(raw, raw + 250000);
        auto end = std::chrono::steady_clock::now(); // end timer
        totalTime += end - start;
    }
    std::cout << "Sort took: " << totalTime.count() << " seconds" << std::endl;
}

void evaluateRawArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated){
    timeRawArray(random);
    timeRawArray(sorted);
    timeRawArray(reversed);		
    timeRawArray(organPipe);
    timeRawArray(rotated);
}


void evaluateStdArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated){
    std::cout << "evaluate STD Array" << std::endl;
    std::cout << sorted.size() << std::endl;
    std::cout << random.size() << std::endl;
    std::cout << reversed.size() << std::endl;
    std::cout << rotated.size() << std::endl;
    std::cout << organPipe.size() << std::endl;
}

void evaluateStdVector(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated){
    std::cout << "evaluate std::vector" << std::endl;
    std::cout << sorted.size() << std::endl;
    std::cout << random.size() << std::endl;
    std::cout << reversed.size() << std::endl;
    std::cout << rotated.size() << std::endl;
    std::cout << organPipe.size() << std::endl;
    // copy into std vector
    // sort HOW_MANY_TIMES
}
