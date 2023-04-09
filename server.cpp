#include <iostream>
#include <string>
#include <algorithm>
#include "httplib.h"

int main() {
    httplib::Server svr;

    // hi
    svr.Get("/hi", [](const httplib::Request &, httplib::Response &res) {
        res.set_content("Hello World!", "text/plain");
    });
    std::cout << "listen: http://localhost:8080/hi" << std::endl;

    // reverse
    svr.Get("/reverse", [](const httplib::Request& req, httplib::Response& res) {
        std::string text = req.get_param_value("text");
        std::reverse(text.begin(), text.end());
        res.set_content(text, "text/plain");
    });
    std::cout << "listen: http://localhost:8080/reverse?text=hello" << std::endl;

    int counter = 0;
    svr.Get("/counter", [&counter](const httplib::Request& req, httplib::Response& res) {
        counter += 1;
        res.set_content(std::to_string(counter), "text/plain");
    });
    std::cout << "listen: http://localhost:8080/counter" << std::endl;
    
    // listen
    svr.listen("0.0.0.0", 8080);

    return 0;
}