#include "_utils.h"

constexpr auto M_PI = 3.14159265358979323846264338327950288;

float degreesToRadians(float degrees)
{
	return (degrees * (M_PI / 180.0f));
}