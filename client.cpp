#include <iostream>
#include <string>
#include <map>
#include "httplib.h"

std::string http_get(
    std::string host = "localhost",
    int port = 8080,
    std::string path = "/hi",
    std::map<std::string, std::string> req = {}
) {
    // query parameter繋げる
    for (auto it = req.begin(); it != req.end(); it++) {
        if (it == req.begin()) path += "?";
        else path += "&";
        path += it->first + "=" + it->second;
    }
    // clientでgetして結果返す
    httplib::Client cli(host, port);
    auto res = cli.Get(path);
    if (res) return res->body;
    return "";
}

void pr(std::string content) {
    std::cout << content << std::endl;
}

int main() {
    std::string host = "localhost";
    int port = 8080;
    pr(http_get(host, port, "/hi"));
    pr(http_get(host, port, "/reverse", {{"text", "hello"}}));
    pr(http_get(host, port, "/counter"));
    pr(http_get(host, port, "/counter"));
    pr(http_get(host, port, "/counter"));

    return 0;
}