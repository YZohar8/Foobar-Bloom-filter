# BloomFilter
In this section, we have enhanced our BloomFilter implementation to include a robust multithreaded C++ TCP HTTP server. This server efficiently handles HTTP requests from clients, utilizing the Bloom filter to check for blacklisted URLs. The Bloom filter, a probabilistic data structure, excels in speed and memory efficiency, making it ideal for quickly determining whether a URL is allowed or blocked based on a set of predefined criteria. This server-client architecture is designed to manage multiple client requests concurrently, ensuring high performance and scalability. By implementing a TCP server, we ensure reliable data transmission and maintain a continuous connection state, which is crucial for real-time interactions and data integrity. The development process was driven by a Test-Driven Development (TDD) approach, focusing initially on essential functionalities such as blacklist checks and Bloom filter operations, followed by extensive class implementations and refactoring to promote modularity and ease of maintenance.

## Prerequisites
You will need `cmake` to build the C++ project. Execute the following commands to install `cmake`:

```sh
sudo apt-get update
sudo apt-get install libgtest-dev cmake
```

## Installation
1. Clone this repository:
```sh
git clone https://github.com/Yzohar8/Foober-Bloom-Filter.git
```
2. Create and build a `build` directory using `cmake`:
```sh
cmake -B build -S .
cmake --build build
```



Enjoy!
