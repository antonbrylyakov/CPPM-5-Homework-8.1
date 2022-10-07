#pragma once
#include <exception>

class BadLength: public std::exception
{
public:
	const char* what() const override;
};

