
// Copyright (c) 2012 Christopher Lux <christopherlux@gmail.com>
// Distributed under the Modified BSD License, see license.txt.

#include <scm/core/platform/platform.h>

#if    SCM_COMPILER     == SCM_COMPILER_MSVC \
    && SCM_COMPILER_VER >= 1400

#pragma warning(push)               // preserve warning settings

// Turn off warnings generated by long std templates
// This warns about truncation to 255 characters in debug/browse info
#pragma warning (disable : 4786)

// 'identifier' : decorated name length exceeded, name was truncated
#pragma warning (disable : 4503)

// 'identifier' : class 'type' needs to have dll-interface to be used by clients of class 'type2'
#pragma warning (disable : 4251)

// non � DLL-interface classkey 'identifier' used as base for DLL-interface classkey 'identifier'
#pragma warning (disable : 4275)

// 'function': was declared deprecated (VC8 for some/all C calls)
#pragma warning( disable: 4996)

// C++ exception specification ignored except to indicate a function is not __declspec(nothrow)
#pragma warning( disable: 4290)

// decorated name length exceeded, name was truncated
#pragma warning( disable: 4503)

#endif //    SCM_COMPILER     == SCM_COMPILER_MSVC
       // && SCM_COMPILER_VER >= 1400
