#include <iostream>
#include <tensor.hpp>

dl::tensor::Tensor<float> tensor{{1.5, 2.5, -1, -2.5}, {2, 2}};

int main()
{
    tensor.print();
    tensor.reshape({2, 1, 2});
    tensor.print();
    return 0;
}
