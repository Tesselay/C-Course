#pragma once

class Mystring
{
public:
		Mystring();			// No args constructor
		Mystring(const char* s);			// Overloaded constructor
		Mystring(const Mystring &source);			// Copy constructor
		~Mystring();			// Destructor

		Mystring &operator=(const Mystring& source);			// Overloading operator =
		Mystring operator-() const;				// Overloading operator -
		Mystring operator+(const Mystring& pMystring) const;			// Overloading operator +
		bool operator==(const Mystring& pMystring) const;			// Overloading operator ==

		// Member Methods
		void display() const;
		int get_length() const;
		const char* get_str() const;

protected:

private:
		// Member Data
		char* str;			// Pointer to a char[] that holds a C-style string

};
