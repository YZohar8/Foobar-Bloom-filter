// src/HashFunction.h
#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H

std::function<size_t(const std::string&)> createHashFunction (int rounds);

#endif