// src/logicToBloomFilter.h
#ifndef LOGICTOBLOOMFILTER_H
#define LOGICTOBLOOMFILTER_H

// the function get string(line) and check that all the char in the string is digit or space
bool isValidInput (std::string& input);

// thr function recieve from user urls and filter them
void getUrls (BloomFilter bloomFilter);

// the function recieve from user information and restart the bloom filter 
int getFirstLine (size_t& bloom_size, std::vector<size_t>& rounds_hash);

#endif