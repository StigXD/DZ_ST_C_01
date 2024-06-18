#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;

// Обработка исключений

//int Convert(const string str)
//{
//	long long value = 0;
//	int minValue = 48;
//	int maxSize = 10;
//	int countSymbols = 0;
//
//	if (str == "")
//		throw "String is empty";
//
//	for (int i = 0; i < str.length(); i++)
//		if (!isdigit(str[i]))
//			throw "String included char!";
//		
//	for (int i = 0; i < str.length(); i++)
//	{
//		countSymbols++;
//		if (countSymbols > maxSize)
//			throw "String is too long";
//	}
//	
//	for (int i = 0; i < str.length(); i++)
//	{
//		value = value * 10 + (str[i] - '0');
//	}
//
//
//	return value;
//
//}
//
//void main()
//{
//	string str = "123";
//	try
//	{
//		cout << "Recived int: " << Convert(str) << endl;
//	}
//	catch (const char* error)
//	{
//		cout << "Error on convert: " << error << endl;
//	}
//	system("pause");
//}



class Figure
{


public:
	
	virtual ~Figure() = default;

	virtual double GetArea() = 0;

	virtual string ToString() = 0;
};

class Square : public Figure
{
	static double x;

public:

	Square()
	{
		x = 0;
	}

	static Square* FromString(const string& str) 
	{
		if (str.starts_with("Square"))
		{
			for (int i = 0; str[i] != '\0'; i++)
				if (isdigit(str[i]))
					x += str[i] - 48;
		}

	}

	double GetArea() override
	{
		return x * x;
	}

	string ToString() override
	{
		string str;
		str = "Square " + to_string(x);
		return str;
	}
};

class Rectangle : public Figure
{
	static double x;
	static double y;

public:
	static Rectangle FromString(const string& str)
	{

	}

};
//
//class Circle : public Figure
//{
//	static double r;
//
//public:
//	static Circle FromString(const string& str)
//	{
//
//	}
//
//};
//
//class Trapezoid : public Figure
//{
//	static double lengthBase;
//	static double higth;
//
//
//public:
//	static Trapezoid FromString(const string& str)
//	{
//
//	}
//
//};

class FigureCollection
{

	vector <Figure*>* figures;
	string inputStr;

public:
	
	FigureCollection()
	{
		figures = new vector <Figure*>;
	}

	~FigureCollection()
	{
		Save(figures);
		for (int i = 0; i < figures.size(); i++)
			delete figures[i];
	}

	void Save(const vector <Figure*> figures)
	{
		ofstream file;
		file.open("FigureCollection");
		if (file.is_open())
			for (int i = 0; i < figures.size(); i++)
				file << figures.at(i)->ToString();
		file.close();
	}
	
	void Load()
	{
		ifstream file;
		file.open("FigureCollection");
		if (file.is_open())
			while(!file.eof())
				getline(file, inputStr);
		file.close();

	}
};

void main()
{
	
	
	system("pause");
}