#pragma once
#include <cassert>

#define MD_ASSERT(cond) assert(cond)

#define MD_ENABLE true
#define MD_DISABLE false

#ifdef MD_FORCE_COLUMN_MAJOR_ORDERING
#	undef MD_FORCE_COLUMN_MAJOR_ORDERING
#	define MD_FORCE_COLUMN_MAJOR_ORDERING MD_ENABLE
#else
#	define MD_FORCE_COLUMN_MAJOR_ORDERING MD_DISABLE
#endif
