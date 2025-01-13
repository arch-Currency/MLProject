#include <iostream>
#include <tensor.hpp>
#include "util.hpp"

dl::tensor::Tensor<float> tensor{{1.5, 2.5, -1, -2.5, 5, 6}, {2, 3, 1}};

int main()
{
    tensor.print();

    return 0;
}
