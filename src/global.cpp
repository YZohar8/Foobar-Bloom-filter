#include "global.h"
#include <vector>


int portServer = 8081;
int countToResetTheBloomFilter = 2;
size_t bloomFilterSizeToReset = 512;
std::vector<size_t> roundsHashToReset = {1, 2};

