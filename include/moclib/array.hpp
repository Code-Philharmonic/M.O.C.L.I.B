#ifndef MOCLIB_ARRAY_HPP
#define MOCLIB_ARRAY_HPP

#include "types.hpp"
#include "matrix.hpp"

namespace moclib {

// MARK: - Image Buffer Allocator

// MARK: - Input Output Array Arguments

class MOCLIB_EXPORTS InputArray_ {
public:
    // Default Constructor
    InputArray_() noexcept = default;
    // Construct from Mat
    InputArray_(const Matrix& m);

    // Construct from std::vector<Type>
    template<typename Type>
    InputArray_(const std::vector<Type>& vec);

    // Construct from std::array<Type, N>
    template<typename Type, std::size_t N>
    InputArray_(const std::array<Type, N>& arr);

    // Construct from a single scalar value
    template<typename Type>
    InputArray_(const Type& scalar);

    // Construct from a raw pointer and size
    template<typename Type>
    InputArray_(const Type* data, std::size_t size);
};

class MOCLIB_EXPORTS OutputArray_ {
public:
    OutputArray_();
};

} // namespace moclib

#endif // MOCLIB_ARRAY_HPP