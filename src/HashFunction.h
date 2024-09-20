// src/HashFunction.h
#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H

// create new hash function base on std::hash
std::function<size_t(const std::string&)> createHashFunction(int rounds);

#endif