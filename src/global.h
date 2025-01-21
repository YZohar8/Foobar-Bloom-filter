#ifndef GLOBAL_H
#define GLOBAL_H

#include <vector>

extern int portServer;
extern int countToResetTheBloomFilter;
extern size_t bloomFilterSizeToReset;
extern std::vector<size_t> roundsHashToReset;

#endif // GLOBAL_H