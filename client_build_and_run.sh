set -e
curl https://raw.githubusercontent.com/yhirose/cpp-httplib/master/httplib.h -o httplib.h
g++ client.cpp -std=c++11 -O3 -o client.out
./client.out
