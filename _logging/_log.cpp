#include "_log.h"

void logError(const char* file, const char* func, int line, const char* msg)
{
	std::cout << "\n" << "ERROR::" << msg << std::endl << "FILE::" << file << " FUNC::" << func << " LINE::" << line << std::endl;
}

void logError(const char* file, int line, const char* msg)
{
	std::cout << "\n" << "ERROR::" << msg << std::endl << "FILE::" << file << " LINE::" << line << std::endl;
}

void logWarning(const char* file, int line, const char* msg)
{
	std::cout << "\n" << "WARNING::" << msg << std::endl << "FILE::" << file << " LINE::" << line << std::endl;
}
