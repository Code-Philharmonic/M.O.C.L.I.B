#ifndef MOCLIB_VERSION_HPP
#define MOCLIB_VERSION_HPP

// MARK: - Version Components

// Major version number (incompatible API changes)
#define MOCLIB_VERSION_MAJOR 0
// Minor version number (backwards-compatible features)
#define MOCLIB_VERSION_MINOR 1
// Patch/Revision number (backwards-compatible fixes)
#define MOCLIB_VERSION_PATCH 0

// Pre-release status (dev, alpha, beta, rc, stable)
#define MOCLIB_VERSION_STATUS "-dev"

// MARK: - String Conversion Macros

// Internal macro for stringification (do not use directly)
#define MOCLIB_AUX_STR_EXP(__A)  #__A
// Converts macro argument to string literal 
#define MOCLIB_AUX_STR(__A)      MOCLIB_AUX_STR_EXP(__A)

// Internal macro for wide string (do not use directly)
#define MOCLIB_AUX_STRW_EXP(__A) L ## #__A
// Converts macro argument to wide string literal
#define MOCLIB_AUX_STRW(__A)     MOCLIB_AUX_STRW_EXP(__A)

// MARK: - Version Strings

// Version string in format "MAJOR.MINOR.PATCH-STATUS"
#define MOCLIB_VERSION_STRING \
    MOCLIB_AUX_STR(MOCLIB_VERSION_MAJOR) "." \
    MOCLIB_AUX_STR(MOCLIB_VERSION_MINOR) "." \
    MOCLIB_AUX_STR(MOCLIB_VERSION_PATCH) \
    MOCLIB_VERSION_STATUS

// MARK: - Numeric Version

// Combines version components into single integer
#define MOCLIB_VERSION_INT(a, b, c) (((a) << 16) | ((b) << 8) | (c))

// Current version as comparable integer
#define MOCLIB_VERSION_NUMBER \
    MOCLIB_VERSION_INT(MOCLIB_VERSION_MAJOR, MOCLIB_VERSION_MINOR, MOCLIB_VERSION_PATCH)

#endif // MOCLIB_VERSION_HPP
