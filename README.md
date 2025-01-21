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
git clone https://github.com/YZohar8/Foobar-Bloom-filter.git
cd Foobar-Bloom-filter
git checkout Part-4
```
2. Create and build a `build` directory using `cmake`:
```bash
rm -rf build
cmake -B build -S .
cmake --build build
```

### Run the Application

1. Execute the main program:
   ```bash
   ./build/MainApp
   ```
   Example:
   - Enter inputs in the defined format (e.g., 1 [URL] or 2 [URL]) in the command line.

---

# Alternative Way to Run the Project Using Docker

If you'd like to run the project using Docker, you can do so by building a Docker image and running it as a container. This is an efficient and portable way to ensure the project runs in a consistent environment.

## Steps to Run the Project

1. Create and build a `build` directory using `cmake`:
   ```bash
   rm -rf build
   cmake -B build -S .
   cmake --build build
   ```

2. **Build the Docker Image**  
   look to Docker Integration.

3. **Run the Command**  
   After the image is built, you can run the project by executing the following command:

   ```bash
   docker run -i -t -p 8081:8081 <your-dockerhub-username>/bloom-filter-server:<tag>
   ```
   Replace `<your-dockerhub-username>` with your Docker Hub username.



### Docker Integration

To make deployment easier, you can use Docker to build and run the server.

1. **Build the Docker Image**:
   ```bash
   docker build -t <your-dockerhub-username>/bloom-filter-server:<tag> .
   ```
   Replace `<your-dockerhub-username>` with your Docker Hub username.

2. **Push the Image to Docker Hub**:
   first login to your docker
   ```bash
   docker login
   docker push <your-dockerhub-username>/bloom-filter-server:<tag>
   ```
   Replace `<your-dockerhub-username>` with your Docker Hub username.

---

Enjoy!

