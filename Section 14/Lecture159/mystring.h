#pragma once

class Mystring
{
public:
	Mystring();			// No args constructor
	Mystring(const char* s);			// Overloaded constructor
	Mystring(const Mystring &source);			// Copy constructor
	~Mystring();			// Destructor

protected:

private:
	// Member Methods
	void display() const;
	int get_length() const;
	const char* get_str() const;

	// Member Data
	char* str;			// Pointer to a char[] that holds a C-style string

};
