set -e
curl https://raw.githubusercontent.com/yhirose/cpp-httplib/master/httplib.h -o httplib.h
g++ server.cpp -std=c++11 -O3 -o server.out
./server.out
