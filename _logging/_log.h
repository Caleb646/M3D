#pragma once
#ifndef LOG_H
#define LOG_H

#include <iostream>

void logError(const char* file, const char* func, int line, const char* msg);
void logError(const char* file, int line, const char* msg);
void logWarning(const char* file, int line, const char* msg);

#endif