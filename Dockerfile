FROM ubuntu:20.04

RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    git \
    build-essential \
    libgtest-dev \
    lcov \
    wget

RUN apt-get update && apt-get install -y cmake && \
    cd /usr/src/gtest && \
    cmake CMakeLists.txt && \
    make && \
    cp *.a /usr/lib

WORKDIR /app
COPY . .

RUN mkdir build
WORKDIR /app/build
RUN cmake .. && make

RUN ctest

CMD ["./run"]