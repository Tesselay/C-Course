#include <iostream>

#include "mystring.h"

using namespace std;

int main(int argc, char *argv[])
{
	Mystring empty;
	Mystring larry ("Larry");
	Mystring stooge {larry};

	empty.display();
	larry.display();
	stooge.display();

	return 0;
}
