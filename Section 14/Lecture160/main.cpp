#include <iostream>

#include "mystring.h"

using namespace std;

int main(int argc, char *argv[])
{
	Mystring obj1 {"Hello"};
	Mystring obj2 {"World"};

	obj1.display();
	obj2.display();

	obj1 = obj2;

	obj1.display();
	obj2.display();

	return 0;
}
