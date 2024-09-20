// src/HashFunction.h
#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H

// create new hash function base on std::hash and how mauch times you run the function on the input
std::function<size_t(const std::string&)> createHashFunction(int rounds);

#endif