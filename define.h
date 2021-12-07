#pragma once
#include <cassert>

#define MD_ASSERT(cond) assert(cond)

#define MD_ENABLED true
#define MD_DISABLED false

#ifdef MD_FORCE_COLUMN_MAJOR_ORDERING
#	undef MD_FORCE_COLUMN_MAJOR_ORDERING
#	define MD_FORCE_COLUMN_MAJOR_ORDERING MD_ENABLED
#	pragma message("[M3D] Column Major Ordering Forced")
#else
#	define MD_FORCE_COLUMN_MAJOR_ORDERING MD_DISABLED
#endif

#ifdef MD_FORCE_DEPTH_ZERO_TO_ONE
#	undef MD_FORCE_DEPTH_ZERO_TO_ONE
#	define MD_FORCE_DEPTH_ZERO_TO_ONE MD_ENABLED
#	pragma message("[M3D] Depth Forced Between 0 - 1")
#else
#	define MD_FORCE_DEPTH_ZERO_TO_ONE MD_DISABLED
#endif
