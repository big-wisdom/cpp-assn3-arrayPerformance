#include <iostream>
#include <algorithm>
#include "sortutils.hpp"

void initializeRawArrayFromStdArray(const SourceArray& source, int dest[]){
    std::copy(source.begin(), source.end(), dest);
}

void organPipeStdArray(SourceArray& data){
    std::cout << "organ pipe" << std::endl;
    std::cout << data.size() << std::endl;
}

void evaluateRawArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated){
    std::cout << sorted.size() << std::endl;
    // copy into raw array
    std::cout << random.size() << std::endl;
    // copy into raw array
    std::cout << reversed.size() << std::endl;
    // copy into raw array
    std::cout << rotated.size() << std::endl;
    // copy into raw array
    std::cout << organPipe.size() << std::endl;
    // copy into raw array

    // sort HOW_MANY_TIMES
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
