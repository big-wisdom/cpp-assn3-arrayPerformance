#include <iostream>
#include <algorithm>
#include <chrono>
#include <execution>
#include "sortutils.hpp"

void initializeRawArrayFromStdArray(const SourceArray& source, int dest[]){
    std::copy(source.begin(), source.end(), dest);
}

void organPipeStdArray(SourceArray& data){
    if((data.size() % 2) == 0){
        std::reverse_copy(data.begin(),data.begin()+ data.size()/2, data.begin()+(data.size()/2));
    } else {
        std::reverse_copy(data.begin(),data.begin()+ data.size()/2, data.begin()+(data.size()/2)+1);
    }
}

void timeRawArray(SourceArray sa)
{
    std::chrono::duration<double> totalTime = std::chrono::steady_clock::duration::zero();
    for(int i=0; i < HOW_MANY_TIMES; i++)
    {
        int raw[250000];
        initializeRawArrayFromStdArray(sa, raw);
        auto start = std::chrono::steady_clock::now(); // start timer
        std::sort(std::execution::seq ,raw, raw + 250000);
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

void timeStdArray(SourceArray source){

    std::chrono::duration<double> totalTime = std::chrono::steady_clock::duration::zero();
    for(int i=0; i < HOW_MANY_TIMES; i++)
    {
        std::array<int, 250000> sa;
        std::copy(source.begin(), source.end(), sa.begin());
        auto start = std::chrono::steady_clock::now(); // start timer
        std::sort(sa.begin(), sa.end());
        auto end = std::chrono::steady_clock::now(); // end timer
        totalTime += end - start;
    }
    std::cout << "Sort took: " << totalTime.count() << " seconds" << std::endl;
}

void evaluateStdArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated){
    timeStdArray(random);
    timeStdArray(sorted);
    timeStdArray(reversed);		
    timeStdArray(organPipe);
    timeStdArray(rotated);
}

void timeStdVector(SourceArray source)
{
    std::chrono::duration<double> totalTime = std::chrono::steady_clock::duration::zero();
    for(int i=0; i < HOW_MANY_TIMES; i++)
    {
        std::vector<int> vector;
        std::copy(source.begin(), source.end(), std::back_inserter(vector));
        auto start = std::chrono::steady_clock::now(); // start timer
        std::sort(vector.begin(), vector.end());
        auto end = std::chrono::steady_clock::now(); // end timer
        totalTime += end - start;
    }
    std::cout << "Sort took: " << totalTime.count() << " seconds" << std::endl;
}

void evaluateStdVector(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated){
    timeStdVector(random);
    timeStdVector(sorted);
    timeStdVector(reversed);		
    timeStdVector(organPipe);
    timeStdVector(rotated);
}
