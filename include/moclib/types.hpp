#ifndef MOCLIB_TYPES_HPP
#define MOCLIB_TYPES_HPP

#include <cstdint>
#include <vector>   
#include <type_traits>
#include <span>
#include <array>

#include "moclibdef.h"

namespace moclib {

template<typename Type> class Point_ {
public:
    using value_type = Type;

    // Default Constructor
    constexpr Point_() noexcept = default;
    // Constructor with coordinates
    constexpr Point_(Type x, Type y) noexcept : x(x), y(y) {}
    // Copy and Move Constructors
    constexpr Point_(const Point_&) noexcept = default;
    constexpr Point_(Point_&&) noexcept = default;
    // Constructor from Size
    constexpr explicit Point_(const Size_<Type>& sz) noexcept : x(sz.width), y(sz.height) {}
    // Constructor from Vector
    constexpr explicit Point_(const Vector<Type, 2>& v) noexcept : x(v[0]), y(v[1]) {}
};

using Point2i = Point_<int>;    
using Point2l = Point_<int64_t>; 
using Point2f = Point_<float>;    
using Point2d = Point_<double>; 
using Point = Point2i; 

template<typename Type> class Size_ {
public:
    using value_type = Type;

    // Default Constructor
    constexpr Size_() noexcept = default;
    // Constructor with dimensions
    constexpr Size_(Type width, Type height) noexcept : width(width), height(height) {}
    // Copy and Move Constructors
    constexpr Size_(const Size_&) noexcept = default;
    constexpr Size_(Size_&&) noexcept = default;

    // Constructor from Point
    constexpr explicit Size_(const Point<Type>& pt) noexcept : width(pt.x), height(pt.y) {}

    // The area (width * height)
    [[nodiscard]] constexpr Type area() const noexcept { return width * height; }
    
    // Aspect ratio (width / height)
    [[nodiscard]] constexpr double aspectRatio() const noexcept { 
        return static_cast<double>(width) / static_cast<double>(height); 
    }

    // True if empty
    [[nodiscard]] constexpr bool empty() const noexcept { return width <= 0 || height <= 0; }

    // Conversion to another data type
    template<typename Type2>
    [[nodiscard]] constexpr explicit operator Size_<Type2>() const noexcept {
        return Size<Type2>{static_cast<Type2>(width), static_cast<Type2>(height)};
    }

    Type width {};
    Type height {};
};

using Size2i = Size_<int>;
using Size2l = Size_<int64_t>;
using Size2f = Size_<float>;
using Size2d = Size_<double>;
using Size = Size2i;

template<typename Type> class Scalar_ {
public:
    using value_type = Type;

    // Default Constructor
    constexpr Scalar_() noexcept = default;
    // Constructor with four values
    constexpr Scalar_(Type v0, Type v1, Type v2, Type v3) noexcept : val{v0, v1, v2, v3} {}
    // Copy and Move Constructors
    constexpr Scalar_(const Scalar_& s) noexcept = default;
    constexpr Scalar_(Scalar_&& s) noexcept = default;

    // Return a scalar with all elements set to v0
    static constexpr Scalar_<Type> all(Type v0) noexcept {
        return Scalar_<Type>(v0, v0, v0, v0);
    }

    // Conversion to another data type
    template<typename Type2>
    [[nodiscard]] constexpr explicit operator Scalar_<Type2>() const noexcept {
        return Scalar_<Type2>{
            static_cast<Type2>(val[0]),
            static_cast<Type2>(val[1]),
            static_cast<Type2>(val[2]),
            static_cast<Type2>(val[3])
        };
    }

    // Per-element product
    [[nodiscard]] constexpr Scalar_<Type> mul(const Scalar_<Type>& s) const noexcept {
        return Scalar_<Type>(
            val[0] * s.val[0],
            val[1] * s.val[1],
            val[2] * s.val[2],
            val[3] * s.val[3]
        );
    }

    // Returns (v0, -v1, -v2, -v3)
    [[nodiscard]] constexpr Scalar_<Type> conj() const noexcept {
        return Scalar_<Type>(
            val[0],
            -val[1],
            -val[2],
            -val[3]
        );
    }

    // Returns true if v1 == v2 == v3 == 0
    [[nodiscard]] constexpr bool isReal() const noexcept {
        return val[1] == Type(0) && val[2] == Type(0) && val[3] == Type(0);
    }
};

using Scalar = Scalar_<double>;


} // namespace moclib

#endif // MOCLIB_TYPES_HPP