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
### Step 3: Run Tests

1. Run the tests using `ctest`:
   ```bash
   ctest --test-dir build --output-on-failure
   ```

2. Ensure all tests pass successfully.
---

### Step 4: Run the Application

1. Execute the main program:
   ```bash
   ./build/MainApp
   ```
   Example:
   - Enter inputs in the defined format (e.g., 1 [URL] or 2 [URL]) in the command line.

---


### Docker Integration

To make deployment easier, you can use Docker to build and run the server.

1. **Build the Docker Image**:
   ```bash
   docker build -t bloom-filter <your-dockerhub-username>/bloom-filter:<tag> .
   ```
   Replace `<your-dockerhub-username>` with your Docker Hub username.

2. **Push the Image to Docker Hub**:
   ```bash
   docker login
   docker push <your-dockerhub-username>/bloom-filter:<tag>
   ```
   Replace `<your-dockerhub-username>` with your Docker Hub username.

---

Enjoy!

