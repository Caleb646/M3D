#pragma once
#ifndef _VMATH_H
#define _VMATH_H


#include "_utils.h"

#include "_vector.h"
#include "_vector.cpp"
/*
* 
* 
* vector.cpp and matrix.cpp have to be included here so that there is not
* a linking error due to the template classes.
* 
* 
*/
#include "_matrix.h"
#include "_matrix.cpp"

#endif