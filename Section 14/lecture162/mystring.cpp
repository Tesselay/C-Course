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


Mystring &Mystring::operator=(const Mystring& source)
{
	if (this == &source)
			return *this;
	delete [] str;
	str = new char[std::strlen(source.str) + 1];
	std::strcpy(str, source.str);

	return *this;
}


Mystring Mystring::operator-() const
{
	char* buffer = new char[strlen(this->str) + 1];

	for (size_t i {0}; i < strlen(this->str); i++)
		buffer[i] = tolower(this->str[i]);

	Mystring temp {buffer};
	delete[] buffer;
	return temp;
}


Mystring Mystring::operator+(const Mystring& pMystring) const
{
	char* buffer = new char[strlen(this->str) + strlen(pMystring.str) + 1];
	strcpy(buffer, this->str);
	strcat(buffer, pMystring.str);

	Mystring temp {buffer};
	delete[] buffer;
	return temp;
}


bool Mystring::operator==(const Mystring& pMystring) const
{
	if (strcmp(this->str, pMystring.str) == 0)
		return true;
	else
		return false;
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
