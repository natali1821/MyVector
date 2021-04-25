	#include <iostream>
#include "MyVector.h"

int main()
{
	MyVector first(2);
	first.pushBack(2);
	MyVector second(MyVector(3));
	return 0;
}
