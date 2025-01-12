#include <gtest/gtest.h>
#include "tensor.hpp"
#include "function.hpp"
#include "util.hpp"

TEST(PrintTest, PrintTensor)
{
    dl::tensor::Tensor<float> tensor{{1.5, 2.5, -1, -2.5}, {2, 2}};
    const std::string output = capture_output([&]() { print(tensor.data_mut()); });
    EXPECT_EQ(output, "[1.5, 2.5, -1, -2.5]" "\n");
}

TEST(MutTest, TensorMut)
{
    dl::tensor::Tensor<float> tensor{{1.5, 2.5, -1, -2.5}, {2, 2}};
    auto mut = tensor.data_mut();
    *mut.begin() -= 1;
    EXPECT_EQ(*tensor.data().begin(), 0.5);
}

TEST(MutTest, TensorReshape)
{
    dl::tensor::Tensor<float> tensor{{1.5, 2.5, -1, -2}, {2, 2}};
    tensor.reshape({4, 1});
    const std::string output = capture_output([&]() { print(tensor.shape()); });
    EXPECT_EQ(output, "[4, 1]" "\n");
}

TEST(ValueTest, TensorIndex)
{
    const dl::tensor::Tensor<float> tensor{{1.5, 2.5, -1, -2}, {2, 2}};
    EXPECT_EQ(tensor.at({1, 1}), -2);
}
