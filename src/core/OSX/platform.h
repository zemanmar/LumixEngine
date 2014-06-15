#pragma once

#define STR(X) #X
#define DEFER(M,...) M(__VA_ARGS__)

#define LUX_FORCE_SYMBOL(symbol)
#define NOTE(msg) \
	_Pragma(STR(message("NOTE: " msg " at line " DEFER(STR, __LINE__))))
#define TODO(msg) \
	_Pragma(STR(message("TODO: " msg " at line " DEFER(STR, __LINE__))))
#define WARN(msg) \
	_Pragma(STR(clang warning(msg " at line " DEFER(STR, __LINE__))))

#define LUX_INLINE inline
#define LUX_FORCE_INLINE inline

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

inline int sscanf_s(const char * __restrict s1, const char * __restrict s2, ...)
{
	return 0;
}