#ifndef SLICE_H
#define SLICE_H
#include "evpp/slice.h"
namespace LF
{
	class slice :public evpp::Slice
	{
	public:
		slice(evpp::Slice s) : evpp::Slice(s) {}
		slice() : evpp::Slice(){}

		// Create a slice that refers to d[0,n-1].
		slice(const char* d, size_t n) : evpp::Slice(d,n){}

		// Create a slice that refers to the contents of "s"
		slice(const std::string& s) : evpp::Slice(s) {}

		// Create a slice that refers to s[0,strlen(s)-1]
		slice(const char* s) : evpp::Slice(s) {}
	};
}
#endif // !IF_SLICE_H

