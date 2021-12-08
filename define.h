#pragma once
#include <cassert>

#define MD_ASSERT(cond) assert(cond)

/* Possible Settings */
// M3D_FORCE_COLUMN_MAJOR_ORDERING
// M3D_FORCE_DEPTH_ZERO_TO_ONE
// M3D_UNIT_TESTING


namespace m3d
{
	namespace md_config
	{
		constexpr static bool ENABLED = true;
		constexpr static bool DISABLED = false;

#ifdef M3D_FORCE_COLUMN_MAJOR_ORDERING
		constexpr static bool FORCE_COL_ORDERING = ENABLED;
#		pragma message("[M3D] Column Major Ordering Forced")
#else
		constexpr static bool FORCE_COL_ORDERING = DISABLED;
#endif

#ifdef M3D_FORCE_DEPTH_ZERO_TO_ONE
		constexpr static bool FORCE_DEPTH_ZERO_TO_ONE = ENABLED;
#		pragma message("[M3D] Depth Forced Between 0 - 1")
#else
		constexpr static bool FORCE_DEPTH_ZERO_TO_ONE = DISABLED;
#endif

#ifdef M3D_UNIT_TESTING
		constexpr static bool UNIT_TESTING = ENABLED;
#		pragma message("[M3D] Depth Forced Between 0 - 1")
#else
		constexpr static bool UNIT_TESTING = DISABLED;
#endif
	}
}
