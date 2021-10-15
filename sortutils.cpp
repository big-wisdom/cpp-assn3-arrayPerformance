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

void timeRawArraySeq(SourceArray sa)
{
    std::chrono::duration<double> totalTime = std::chrono::steady_clock::duration::zero();
    for(int i=0; i < HOW_MANY_TIMES; i++)
    {
        int raw[250000];
        initializeRawArrayFromStdArray(sa, raw);
        auto start = std::chrono::steady_clock::now(); // start timer
        std::sort(std::execution::seq,raw, raw + 250000);
        auto end = std::chrono::steady_clock::now(); // end timer
        totalTime += end - start;
    }
    std::cout << "Sort took: " << totalTime.count() << " seconds" << std::endl;
}

void timeRawArrayPar(SourceArray sa)
{
    std::chrono::duration<double> totalTime = std::chrono::steady_clock::duration::zero();
    for (int i = 0; i < HOW_MANY_TIMES; i++)
    {
        int raw[250000];
        initializeRawArrayFromStdArray(sa, raw);
        auto start = std::chrono::steady_clock::now(); // start timer
        std::sort(std::execution::par, raw, raw + 250000);
        auto end = std::chrono::steady_clock::now(); // end timer
        totalTime += end - start;
    }
    std::cout << "Sort took: " << totalTime.count() << " seconds" << std::endl;
}

void evaluateRawArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated){
    std::cout << "Sequential" << std::endl;
    timeRawArraySeq(random);
    timeRawArraySeq(sorted);
    timeRawArraySeq(reversed);
    timeRawArraySeq(organPipe);
    timeRawArraySeq(rotated);

    std::cout << "Parallel" << std::endl;
    timeRawArrayPar(random);
    timeRawArrayPar(sorted);
    timeRawArrayPar(reversed);
    timeRawArrayPar(organPipe);
    timeRawArrayPar(rotated);
}

void timeStdArraySeq(SourceArray source){

    std::chrono::duration<double> totalTime = std::chrono::steady_clock::duration::zero();
    for(int i=0; i < HOW_MANY_TIMES; i++)
    {
        std::array<int, 250000> sa;
        std::copy(source.begin(), source.end(), sa.begin());
        auto start = std::chrono::steady_clock::now(); // start timer
        std::sort(std::execution::seq, sa.begin(), sa.end());
        auto end = std::chrono::steady_clock::now(); // end timer
        totalTime += end - start;
    }
    std::cout << "Sort took: " << totalTime.count() << " seconds" << std::endl;
}

void timeStdArrayPar(SourceArray source) {

    std::chrono::duration<double> totalTime = std::chrono::steady_clock::duration::zero();
    for (int i = 0; i < HOW_MANY_TIMES; i++)
    {
        std::array<int, 250000> sa;
        std::copy(source.begin(), source.end(), sa.begin());
        auto start = std::chrono::steady_clock::now(); // start timer
        std::sort(std::execution::par, sa.begin(), sa.end());
        auto end = std::chrono::steady_clock::now(); // end timer
        totalTime += end - start;
    }
    std::cout << "Sort took: " << totalTime.count() << " seconds" << std::endl;
}

void evaluateStdArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated){
    std::cout << "Sequential" << std::endl;
    timeStdArraySeq(random);
    timeStdArraySeq(sorted);
    timeStdArraySeq(reversed);		
    timeStdArraySeq(organPipe);
    timeStdArraySeq(rotated);

    std::cout << "Parallel" << std::endl;
    timeStdArrayPar(random);
    timeStdArrayPar(sorted);
    timeStdArrayPar(reversed);
    timeStdArrayPar(organPipe);
    timeStdArrayPar(rotated);
}

void timeStdVectorSeq(SourceArray source)
{
    std::chrono::duration<double> totalTime = std::chrono::steady_clock::duration::zero();
    for(int i=0; i < HOW_MANY_TIMES; i++)
    {
        std::vector<int> vector;
        std::copy(source.begin(), source.end(), std::back_inserter(vector));
        auto start = std::chrono::steady_clock::now(); // start timer
        std::sort(std::execution::seq, vector.begin(), vector.end());
        auto end = std::chrono::steady_clock::now(); // end timer
        totalTime += end - start;
    }
    std::cout << "Sort took: " << totalTime.count() << " seconds" << std::endl;
}

void timeStdVectorPar(SourceArray source)
{
    std::chrono::duration<double> totalTime = std::chrono::steady_clock::duration::zero();
    for (int i = 0; i < HOW_MANY_TIMES; i++)
    {
        std::vector<int> vector;
        std::copy(source.begin(), source.end(), std::back_inserter(vector));
        auto start = std::chrono::steady_clock::now(); // start timer
        std::sort(std::execution::par, vector.begin(), vector.end());
        auto end = std::chrono::steady_clock::now(); // end timer
        totalTime += end - start;
    }
    std::cout << "Sort took: " << totalTime.count() << " seconds" << std::endl;
}

void evaluateStdVector(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated){
    std::cout << "Sequential" << std::endl;
    timeStdVectorSeq(random);
    timeStdVectorSeq(sorted);
    timeStdVectorSeq(reversed);		
    timeStdVectorSeq(organPipe);
    timeStdVectorSeq(rotated);

    std::cout << "Parallel" << std::endl;
    timeStdVectorPar(random);
    timeStdVectorPar(sorted);
    timeStdVectorPar(reversed);
    timeStdVectorPar(organPipe);
    timeStdVectorPar(rotated);
}
