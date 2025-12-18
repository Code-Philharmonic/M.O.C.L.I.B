#ifndef MOCLIB_MATRIX_HPP
#define MOCLIB_MATRIX_HPP

#include "types.hpp"

namespace moclib {

class MOCLIB_EXPORTS Matrix {
public:
    // Default Constructor
    constexpr Matrix() noexcept = default;

    constexpr Matrix(int rows, int cols, int type);

    constexpr Matrix(Size size, int type);

    constexpr Matrix(int rows, int cols, int type, const Scalar& s);

    constexpr Matrix(Size size, int type, const Scalar& s);

    constexpr Matrix(int ndims, const int* sizes, int type);

    constexpr Matrix(int ndims, const int* sizes, int type, const Scalar& s);

    constexpr Matrix(const std::vector<int>& sizes, int type);

    constexpr Matrix(const std::vector<int>& sizes, int type, const Scalar& s);

    constexpr Matrix(const Matrix& m);
};

} // namespace moclib

#endif // MOCLIB_MATRIX_HPP