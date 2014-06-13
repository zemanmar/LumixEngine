#pragma once

// usefull compile time messages

#define STRINGIZE_2( _ ) #_
#define STRINGIZE( _ ) STRINGIZE_2( _ )

#define JOIN_STRINGS_2(A, B) A ## B
#define JOIN_STRINGS(A, B) JOIN_STRINGS_2(A, B)

#ifdef PC
#define LUX_FORCE_SYMBOL(symbol) \
	__pragma(comment(linker, "/INCLUDE:_" STRINGIZE(symbol)))

#define NOTE(msg)\
	__pragma(message(__FILE__ "(" STRINGIZE(__LINE__) ") : NOTE: " msg))

#define TODO(msg)\
	__pragma(message(__FILE__ "(" STRINGIZE(__LINE__) ") : TODO: " msg))

#define WARN(msg)\
	__pragma(message(__FILE__ "(" STRINGIZE(__LINE__) ") : WARNING: " msg))
#endif //~PC

#ifdef OSX
#define STR(X) #X
#define DEFER(M,...) M(__VA_ARGS__)

#define LUX_FORCE_SYMBOL(symbol)
#define NOTE(msg) \
	_Pragma(STR(message("NOTE: " msg " at line " DEFER(STR,__LINE__))))
#define TODO(msg) \
	_Pragma(STR(message("TODO: " msg " at line " DEFER(STR,__LINE__))))
#define WARN(msg) \
	_Pragma(STR(clang warning(msg " at line " DEFER(STR,__LINE__))))

#endif //~OSX

#include <type_traits>
//#include <cstdint>
#include <cassert>
//#include <malloc.h>

const uint32_t LUX_MAX_PATH = 260;

#ifndef ASSERT
#define ASSERT(x) assert(x)
#endif

#ifndef NULL
#define NULL nullptr
#endif

#ifdef PC
#define LUX_INLINE __inline
#define LUX_FORCE_INLINE __forceinline
#endif //~PC

#if OSX
#define LUX_INLINE inline
#define LUX_FORCE_INLINE inline
#endif //~OSX

#ifdef PC

#ifdef BUILDING_CORE
#define LUX_CORE_API __declspec(dllexport)
#else
#define LUX_CORE_API __declspec(dllimport)
#endif


#ifdef BUILDING_PHYSICS
#define LUX_PHYSICS_API __declspec(dllexport)
#else
#define LUX_PHYSICS_API __declspec(dllimport)
#endif


#ifdef BUILDING_NAVIGATION
#define LUX_NAVIGATION_API __declspec(dllexport)
#else
#define LUX_NAVIGATION_API __declspec(dllimport)
#endif


#ifdef BUILDING_ENGINE
#define LUX_ENGINE_API __declspec(dllexport)
#else
#define LUX_ENGINE_API __declspec(dllimport)
#endif

#ifdef BUILDING_GUI
#define LUX_GUI_API __declspec(dllexport)
#else
#define LUX_GUI_API __declspec(dllimport)
#endif

#endif //~PC

#ifdef OSX

#ifdef BUILDING_CORE
#define LUX_CORE_API
#else
#define LUX_CORE_API
#endif


#ifdef BUILDING_PHYSICS
#define LUX_PHYSICS_API
#else
#define LUX_PHYSICS_API
#endif


#ifdef BUILDING_NAVIGATION
#define LUX_NAVIGATION_API
#else
#define LUX_NAVIGATION_API
#endif


#ifdef BUILDING_ENGINE
#define LUX_ENGINE_API
#else
#define LUX_ENGINE_API
#endif

#ifdef BUILDING_GUI
#define LUX_GUI_API
#else
#define LUX_GUI_API
#endif

#endif //~OSX

#include "core/new.h"
#include "core/new_macros.h"

#pragma warning(disable : 4251)
#pragma warning(disable : 4996)

#ifdef OSX
TODO("Get rid of it!");
TODO("Fix it!");
inline int sscanf_s(const char * __restrict s1, const char * __restrict s2, ...)
{
	return 0;
}
#endif