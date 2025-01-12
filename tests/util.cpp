#include <gtest/gtest.h>
#include "function.hpp"
#include "util.hpp"

TEST(PrintTest, PrintVector)
{
    const std::vector<int> vec = {1, 2, 3, 4, 5};
    const std::string output = capture_output([&]() { print(vec); });
    EXPECT_EQ(output, "[1, 2, 3, 4, 5]" "\n");
}

TEST(PrintTest, PrintArray)
{
    constexpr std::array<double, 5> arr = {1.5, 2.5, 3.5, 4.5, 5.5};
    std::string output = capture_output([&]() { print(arr); });
    EXPECT_EQ(output, "[1.5, 2.5, 3.5, 4.5, 5.5]" "\n");
}

TEST(PrintTest, PrintEmpty)
{
    constexpr std::vector<std::string> vec = {};
    std::string output = capture_output([&]() { print(vec); });
    EXPECT_EQ(output, "[]" "\n");
}
