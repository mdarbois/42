#include <iostream>
#include "Array.hpp"

void	testCopyConstructor(Array<int> & array);
void	testAssignmentOperator(Array<int> & array);

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    ::testCopyConstructor(numbers);
    ::testAssignmentOperator(numbers);
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete [] mirror;
    {
		std::cout << "\tTESTING STRING" << std::endl;

		Array<std::string>	strings(3);
		strings[0] = "Hello";
		strings[1] = "World";
		strings[2] = "!!";
		std::cout <<  "String array (size " << strings.size()
			<< "):\t" << strings << std::endl;
		
		Array<std::string>	anotherString(2);
		anotherString[0] = "Second";
		anotherString[1] = "string";
		std::cout << "Other strings (size " << anotherString.size()
			<< "):\t" << anotherString << std::endl;

		strings = anotherString;
		std::cout << "String array (size " << strings.size()
			<< "):\t" << strings << std::endl;
		try
		{
			strings[3] = "Out of bound index.";
			std::cout << "no exception thrown"  << std::endl;
		}
		catch(const std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
    {
		std::cout <<  "\tTESTING CHAR" << std::endl;

		Array<char>	chars(25);
		for (int i = 0; i < 25; i++)
			chars[i] = 'a' + i;
		std::cout << "Char array (size " << chars.size()
			<< "):\t" << chars << std::endl;
		
		Array<char>	anotherChar(15);
		for (int i = 0; i < 15; i++)
			anotherChar[i] = 'Z' - i;
		std::cout << "Other Chars (size " << anotherChar.size()
			<< "):\t" << anotherChar << std::endl;

		chars = anotherChar;
		std::cout << "Char array (size " << chars.size()
			<< "):\t" << chars << std::endl;
		try
		{
			chars[15] = '~';
			std::cout << "no exception thrown"  << std::endl;
		}
		catch(const std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
    }
    return 0;
}

void	testCopyConstructor(Array<int> & array)
{
	std::cout << std::endl << "TEST COPY CONSTRUCTOR" << std::endl;
	bool	ok = true;
	std::cout << "Array (size " << array.size() << "):\t" << array << std::endl;
	
	Array<int> copy(array);
	std::cout << "Copy (size " << copy.size() << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (copy[i] != array[i])
		{
			ok = false;
			std::cout << "[" << copy[i] << "] ";
		}
		else
			std::cout << "[" << copy[i] << "] ";
	}
	if (ok == false)
		 std::cout << "KO: Copy values do not match original array values."<< std::endl;
	else
		std::cout << "OK." << std::endl;
}

void	testAssignmentOperator(Array<int> & array)
{
	std::cout << std::endl << "TEST ASSIGNMENT OPERATOR" << std::endl;
	std::cout << "Array (size " << array.size() << "):\t\t" << array << std::endl;
	Array<int> zeroArray(5);
	for (int i = 0; i < 5; i++)
		zeroArray[i] = 0;
	std::cout << "Zero Array (size " << zeroArray.size() << "):\t\t" << zeroArray << std::endl;
	array = zeroArray;
	std::cout << "Array assigned (size " << array.size() << "):\t" << array << std::endl;
	Array<int> oneArray(25);
	for (int i = 0; i < 25; i++)
		oneArray[i] = 1;
	std::cout << "One Array (size " << oneArray.size() << "):\t\t" << oneArray << std::endl;
	array = oneArray;
	std::cout << "Array assigned (size " << array.size() << "):\t" << array << std::endl;
}