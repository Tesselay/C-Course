#include <iostream>
#include "mystring.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << boolalpha << endl;

	Mystring larry {"Larry"};
	Mystring moe {"Moe"};

	Mystring stooge = larry;
	larry.display();
	moe.display();

	cout << (larry == moe) << endl;
	cout << (larry == stooge) << endl;

	larry.display();
	Mystring larry2 = -larry;
	larry2.display();

	Mystring stooges = larry + "Moe";
//	Mystring stooges = "Larry" + moe;			// Compiler error (left side object can't be string literal)
//	Can be understood as => "Larry".operator+(moe)

	Mystring two_stooges = moe + " " + "Larry";
	two_stooges.display();

	Mystring three_stooges = moe + " " + larry + " " + "Curly";
	three_stooges.display();

	return 0;
}
