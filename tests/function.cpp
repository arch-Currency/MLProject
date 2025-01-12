#include <sstream>
#include <iostream>
#include "function.hpp"

std::string capture_output(const std::function<void()>& func)
{
    const std::ostringstream oss;
    std::streambuf* original_out = std::cout.rdbuf(oss.rdbuf());
    func();
    std::cout.rdbuf(original_out);
    return oss.str();
}