#include <iostream>
#include "IntegerArray.h"
#include<exception>

using namespace std;

int main()
{
	IntegerArray array(10);

	for (int i{ 0 }; i < 10; ++i)
	{
		array[i] = i + 1;
	}

	try
	{
		array.resize(8);
	}
	catch (const std::exception& err)
	{
		cout << "Error" << err.what() << endl;
	}

	try
	{
		array.insertBefore(20, 5);
	}
	catch (const std::exception& err)
	{
		cout << "Error!!! " << err.what() << endl;
	}

	array.remove(3);

	array.insertAtEnd(30);

	array.insertAtBeginning(40);

	{
	    IntegerArray b{ array };
	    b = array;
	    b = b;
	    array = array;
	}

	array.printArray();

	return 0;
}

