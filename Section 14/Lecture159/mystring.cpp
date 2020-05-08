#include "mystring.h"

#include <iostream>
#include <cstring>

Mystring::Mystring()
	: str(nullptr)
{
	str = new char[1];
	*str = '\0';			// Instead of having to handle null pointer cases, create an empty object
}


Mystring::Mystring(const char* s)
	: str(nullptr)
{
	if (s==nullptr)
	{
		str = new char[1];
		*str = '\0';
	}
	else
	{
		// Copy content of s to str
		str = new char[std::strlen(s) + 1];			// '...+ 1' to make room for escape char
		std::strcpy(str, s);
	}
}


Mystring::Mystring(const Mystring &source)
	: str(nullptr)
{
	// Creates a deep copy
	str = new char[std::strlen(source.str) + 1];
	std::strcpy(str, source.str);
}


Mystring::~Mystring()
{
	delete []str;
}


void Mystring::display() const
{
	std::cout << str << ":" << get_length() << std::endl;
}


int Mystring::get_length() const
{
	return std::strlen(str);
}


const char* Mystring::get_str() const
{
	return str;
}
