#pragma once

// usefull compile time messages

#define STRINGIZE_2( _ ) #_
#define STRINGIZE( _ ) STRINGIZE_2( _ )

#define JOIN_STRINGS_2(A, B) A ## B
#define JOIN_STRINGS(A, B) JOIN_STRINGS_2(A, B)

#ifdef WINDOWS_PLATFORM
#include "core/WIN/platform.h"
#elif OSX_PLATFORM
#else
#error Unsupported platform!
#endif

#include <type_traits>
#include <cassert>

const uint32_t LUX_MAX_PATH = 260;

#ifndef ASSERT
#define ASSERT(x) assert(x)
#endif

#ifndef NULL
#define NULL nullptr
#endif

#include "core/new.h"
#include "core/new_macros.h"