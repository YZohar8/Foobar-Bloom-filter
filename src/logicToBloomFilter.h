// src/logicToBloomFilter.h
#ifndef LOGICTOBLOOMFILTER_H
#define LOGICTOBLOOMFILTER_H

bool isValidInput (std::string& input);

void getUrls (BloomFilter bloomFilter);

int getFirstLine (size_t& bloom_size, std::vector<size_t>& rounds_hash);

#endif