#ifndef UTIL_HPP
#define UTIL_HPP

#include <concepts>
#include <iostream>
#include <iterator>
#include <format>

template <typename T>
concept iterable_sized = requires(T t)
{
    { t.begin() } -> std::input_iterator;
    { t.end() } -> std::input_iterator;
    { t.size() } -> std::same_as<std::size_t>;
};

template <iterable_sized T>
void print(const T& container)
{
    if (container.empty())
    {
        std::cout << "[]" << std::endl;
        return;
    }

    std::cout << '[';
    std::copy(container.begin(), container.end() - 1, std::ostream_iterator<typename T::value_type>(std::cout, ", "));
    std::cout << std::format("{}]", *std::prev(container.end())) << std::endl;
}

#endif //UTIL_HPP
