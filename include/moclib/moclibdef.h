#ifndef MOCLIB_DEFINES_H
#define MOCLIB_DEFINES_H

#include "version.hpp"

// Fundamental Constants
#define MOCLIB_PI 3.1415926535897932384626433832795
#define MOCLIB_2PI 6.283185307179586476925286766559
#define MOCLIB_LOG2 0.69314718055994530941723212145818

// Platform-specific export macros
#if defined(_WIN32)
# if defined(MOCLIB_BUILD)
#   define MOCLIB_EXPORTS __declspec(dllexport)
# else
#   define MOCLIB_EXPORTS __declspec(dllimport)
# endif
#elif defined(__GNUC__) && __GNUC__ >= 4
#   define MOCLIB_EXPORTS __attribute__((visibility("default")))
#else
#   define MOCLIB_EXPORTS
#endif

#ifdef _MSC_VER
#   define MOCLIB_EXPORTS_TEMPLATE
#else
#   define MOCLIB_EXPORTS_TEMPLATE MOCLIB_EXPORTS
#endif

// Special informative macros for wrapper generators
#define MOCLIB_EXPORTS_W MOCLIB_EXPORTS
#define MOCLIB_EXPORTS_AS(synonym) MOCLIB_EXPORTS
#define MOCLIB_EXPORTS_W_PARAMS MOCLIB_EXPORTS
#define MOCLIB_IN_OUT
#define MOCLIB_OUT

#endif // MOCLIB_DEFINES_H