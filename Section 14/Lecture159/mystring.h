#pragma once


class Mystring
{
public:
	Mystring();			// Constructor
	Mystring(const char *s);			// Constructor
	Mystring(const Mystring &source);			// Copy Constructor
	~Mystring();			// Destructor

protected:

private:
	// Member Methods
	void display() const;
	int get_length() const;
	const char *get_str() const;

	// Member Data
	char *str;

};
