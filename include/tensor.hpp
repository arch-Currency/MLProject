#ifndef TENSOR_H
#define TENSOR_H

#include <memory>
#include <vector>
#include <span>

using uint = unsigned int;

namespace dl::tensor
{
    template <typename T>
    class Tensor
    {
        std::shared_ptr<std::vector<T>> _data;
        std::vector<uint> _shape;
        uint _offset;
        uint _length;

    public:
        Tensor(std::vector<T>&&, const std::vector<uint>&);
        Tensor(const std::vector<T>&, const std::vector<uint>&);
        Tensor(const Tensor&);
        Tensor(Tensor&&) noexcept ;
        Tensor& operator=(const Tensor&);
        Tensor& operator=(Tensor&&) noexcept;
        explicit Tensor(const std::vector<uint>&);
        std::span<T> data_mut();
        std::span<const T> data() const;
        [[nodiscard]] const std::vector<uint>& shape() const { return _shape; }
        [[nodiscard]] uint size() const { return _length; }
        void print() const;
        const T& at(const std::vector<uint>&) const;
        void reshape(const std::vector<uint>&);
        Tensor& slice(const std::vector<std::pair<uint, uint>>&);
    };
}

#endif //TENSOR_H
