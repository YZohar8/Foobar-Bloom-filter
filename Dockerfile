FROM gcc:latest

WORKDIR /usr/src/facebookasp

COPY ./src/ .

RUN g++ -o facebookasp *.cpp

EXPOSE 8081

CMD ["./facebookasp"]