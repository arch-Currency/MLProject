#include "tensor.hpp"
#include "util.hpp"
#include <numeric>
#include <format>
#include <iostream>
#include <cassert>

template <typename T>
dl::tensor::Tensor<T>::Tensor(std::vector<T>&& data, const std::vector<uint>& shape)
{
    _length = data.size();
    _data = std::make_shared<std::vector<T>>(std::move(data));
    _shape = shape;
    _offset = 0;
}

template <typename T>
dl::tensor::Tensor<T>::Tensor(const std::vector<T>& data, const std::vector<uint>& shape)
{
    _length = data.size();
    _data = std::make_shared<std::vector<T>>(data);
    _shape = shape;
    _offset = 0;
}

template <typename T>
dl::tensor::Tensor<T>::Tensor(const Tensor<T>& other)
{
    _data = other._data;
    _shape = other._shape;
    _offset = other._offset;
    _length = other._length;
}

template <typename T>
dl::tensor::Tensor<T>::Tensor(Tensor<T>&& other) noexcept
{
    _data = std::move(other._data);
    _shape = std::move(other._shape);
    _offset = other._offset;
    _length = other._length;
    other._offset = 0;
    other._length = 0;
}

template <typename T>
dl::tensor::Tensor<T>& dl::tensor::Tensor<T>::operator=(const Tensor<T>& other)
{
    if (this != &other)
    {
        _data = other._data;
        _shape = other._shape;
        _offset = other._offset;
        _length = other._length;
    }
    return *this;
}

template <typename T>
dl::tensor::Tensor<T>& dl::tensor::Tensor<T>::operator=(Tensor<T>&& other) noexcept
{
    if (this != &other)
    {
        _data = std::move(other._data);
        _shape = std::move(other._shape);
        _offset = other._offset;
        _length = other._length;
        other._offset = 0;
        other._length = 0;
    }
    return *this;
}

template <typename T>
dl::tensor::Tensor<T>::Tensor(const std::vector<uint>& shape)
{
    _length = std::accumulate(shape.begin(), shape.end(), 1, std::multiplies());
    _data = std::make_shared<std::vector<T>>(std::vector<T>(_length));
    _shape = shape;
    _offset = 0;
}

template <typename T>
std::span<T> dl::tensor::Tensor<T>::data_mut()
{
    return std::span(_data->data() + _offset, _length);
}

template <typename T>
std::span<const T> dl::tensor::Tensor<T>::data() const
{
    return std::span(_data->data() + _offset, _length);
}

template <typename T>
void dl::tensor::Tensor<T>::print() const
{
    std::cout << std::format("shape: ");
    ::print(_shape);
    std::cout << std::format("offset: {}\nlength: {}", _offset, _length) << std::endl;
    const uint dim = *(_shape.end() - 1);
    const uint batch = _length / dim;
    for (uint i = 0; i < batch; i++)
    {
        uint start = i * dim + _offset;
        std::span<T> s(_data->data() + start, dim);
        ::print(s);
    }
    std::cout << std::endl;
}

template <typename T>
const T& dl::tensor::Tensor<T>::at(const std::vector<uint>& index) const
{
    assert(index.size() == _shape.size() && "index size must match the tensor shape.");

    std::size_t linear_index = 0;
    std::size_t multiplier = 1;

    for (std::size_t i = 0; i < index.size(); ++i)
    {
        assert(index[i] < shape()[i] && "index out of range.");
        linear_index += index[i] * multiplier;
        multiplier *= shape()[i];
    }

    return data()[linear_index];
}

template <typename T>
void dl::tensor::Tensor<T>::reshape(const std::vector<uint>& new_shape)
{
    auto new_size = std::accumulate(new_shape.begin(), new_shape.end(), 1, std::multiplies());
    assert(new_size == size() && "shape not match tensor.");
    _shape = new_shape;
}

template <typename T>
dl::tensor::Tensor<T>& dl::tensor::Tensor<T>::slice(const std::vector<std::pair<uint, uint>>& index)
{
    assert(index.size() <= _shape.size() && "index size must match the tensor shape.");
    std::vector<uint> new_shape(shape().size(), 0);
    for (auto i = 0; i < shape().size(); i++)
    {
        if (index.size() > i)
        {
            assert(index[i].first < index[i].second && "index out of range.");
            assert(index[i].second <= shape()[i] && "index out of range.");
            new_shape[i] = index[i].second - index[i].first;
            continue;
        }
        new_shape[i] = shape()[i];
    }

    auto length = size();
    const auto new_length = std::accumulate(new_shape.begin(), new_shape.end(), 1, std::multiplies());
    uint offset = 0;

    for (auto i = 0; i < shape().size() && index.size() > i; i++)
    {
        length = length / shape()[i];
        offset += index[i].first * length;
    }

    _shape = std::move(new_shape);
    _length = new_length;
    _offset = offset;

    return *this;
}

template class dl::tensor::Tensor<int>;
template class dl::tensor::Tensor<float>;
