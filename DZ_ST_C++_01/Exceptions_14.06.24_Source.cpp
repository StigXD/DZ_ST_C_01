#include <iostream>
#include <string>

using namespace std;

int Convert(const string str)
{
	long long value = 0;
	int minValue = 48;
	int maxSize = 10;
	int countSymbols = 0;

	if (str == "")
		throw "String is empty";

	for (int i = 0; i < str.length(); i++)
		if (!isdigit(str[i]))
			throw "String included char!";
		
	for (int i = 0; i < str.length(); i++)
	{
		countSymbols++;
		if (countSymbols > maxSize)
			throw "String is too long";
	}
	
	for (int i = 0; i < str.length(); i++)
	{
		value = value * 10 + (str[i] - '0');
	}


	return value;

}

void main()
{
	string str = "123";
	try
	{
		cout << "Recived int: " << Convert(str) << endl;
	}
	catch (const char* error)
	{
		cout << "Error on convert: " << error << endl;
	}
	system("pause");
}