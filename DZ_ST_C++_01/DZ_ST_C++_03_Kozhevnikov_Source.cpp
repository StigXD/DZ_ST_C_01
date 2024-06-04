#include <iostream>
#include <algorithm>
#include <vector>
#include <Windows.h>
#include <stdio.h>
#include <string>
#include <span>

using namespace std;

//������� �6
// 
//������� 1.
//�������� ����� ����� (��� ����������� ��� ����� ��������� ����). ��������� ���������� ���������� ���������� ��� ���� �������������� �������� ��� ������ � �������
//(�������� + , -, *, / ).

//class Fraction
//{
//	int numerator;
//	int denominator;
//
//	int FindNod(int denominator1, int denominator2)
//	{
//		if (denominator1 < denominator2)
//			swap(denominator1, denominator2);
//
//		while (denominator1 % denominator2 != 0)
//		{
//			denominator1 = denominator1 % denominator2;
//			swap(denominator1, denominator2);
//		}
//		return denominator2;
//	}
//	
//	int FindNok(int denominator1, int denominator2)
//	{
//		return denominator1 * denominator2 / FindNod(denominator1, denominator2);
//	}
//
//	void Reduction()
//	{
//		int nod = FindNod(numerator, denominator);
//		if (nod > 1)
//		{
//			numerator /= nod;
//			denominator /= nod;
//		}
//	}
//
//public:
//	Fraction() : Fraction(0, 1)
//	{
//
//	}
//
//	Fraction(int numerator, int denominator)
//	{
//		this->numerator = numerator;
//		this->denominator = denominator;
//	}
//
//	void SetNumerator(int value) { numerator = value; }
//	int GetNumerator() { return numerator; }
//
//	void SetDenominator(int value) { denominator = value; }
//	int GetDenominator() { return denominator; }
//
//	Fraction Addition(const Fraction& otherFract) const
//	{
//		Fraction tempA = *this;
//		Fraction tempB = otherFract;
//
//		const int NOK = FindNok(tempA.denominator, tempB.denominator);
//
//		tempA.numerator *= NOK / tempA.denominator;
//		tempA.denominator = NOK;
//		
//		tempB.numerator *= NOK / tempB.denominator;
//		tempB.denominator = NOK;
//
//		tempA.numerator += tempB.numerator;
//
//		tempA.Reduction();
//		return tempA;
//	}
//
//	Fraction Difference(const Fraction& otherFract) const
//	{
//		Fraction tempA = *this;
//		Fraction tempB = otherFract;
//		
//		int NOK = FindNok(tempA.denominator, tempB.denominator);
//
//		tempA.numerator *= NOK / tempA.denominator;
//		tempA.denominator = NOK;
//
//		tempB.numerator *= NOK / tempB.denominator;
//		tempB.denominator = NOK;
//
//		tempA.numerator -= tempB.numerator;
//
//		tempA.Reduction();
//
//		return tempA;
//	}
//
//	Fraction Multiplication(const Fraction& otherFract) const
//	{
//		Fraction tempA = *this;
//		Fraction tempB = otherFract;
//		
//		tempA.numerator *= tempB.numerator;
//		tempA.denominator *= tempB.denominator;
//
//		tempA.Reduction();
//
//		return tempA;
//	}
//
//	Fraction Degree(const Fraction& otherFract) const
//	{
//		Fraction tempA = *this;
//		Fraction tempB = otherFract;
//		
//		tempA.numerator *= tempB.denominator;
//		tempA.denominator *= tempB.numerator;
//
//		tempA.Reduction();
//
//		return tempA;
//	}
//
//	Fraction operator+(const Fraction& otherFract) const
//	{
//		Fraction tempA = *this;
//		Fraction tempB = otherFract;
//
//		const int NOK = FindNok(tempA.denominator, tempB.denominator);
//
//		tempA.numerator *= NOK / tempA.denominator;
//		tempA.denominator = NOK;
//
//		tempB.numerator *= NOK / tempB.denominator;
//		tempB.denominator = NOK;
//
//		tempA.numerator += tempB.numerator;
//
//		tempA.Reduction();
//		return tempA;
//	}
//
//	Fraction operator-(const Fraction& otherFract) const
//	{
//		Fraction tempA = *this;
//		Fraction tempB = otherFract;
//
//		int NOK = FindNok(tempA.denominator, tempB.denominator);
//
//		tempA.numerator *= NOK / tempA.denominator;
//		tempA.denominator = NOK;
//
//		tempB.numerator *= NOK / tempB.denominator;
//		tempB.denominator = NOK;
//
//		tempA.numerator -= tempB.numerator;
//
//		tempA.Reduction();
//
//		return tempA;
//	}
//
//	Fraction operator*(const Fraction& otherFract) const
//	{
//		Fraction tempA = *this;
//		Fraction tempB = otherFract;
//
//		tempA.numerator *= tempB.numerator;
//		tempA.denominator *= tempB.denominator;
//
//		tempA.Reduction();
//
//		return tempA;
//	}
//
//	Fraction operator/(const Fraction& otherFract)
//	{
//		Fraction tempA = *this;
//		Fraction tempB = otherFract;
//
//		tempA.numerator *= tempB.denominator;
//		tempA.denominator *= tempB.numerator;
//
//		tempA.Reduction();
//
//		return tempA;
//	}
//
//
//	Fraction operator=(const Fraction& otherFract)
//	{
//		numerator = otherFract.numerator;
//		denominator = otherFract.denominator;
//
//		return *this;
//	}
//};
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//	Fraction fract1, fract2, resultFract;
//	int numerator, denominator;
//
//	cout << "����� 1:" << endl;
//	cout << "������� ���������" << endl;
//	cin >> numerator;
//	fract1.SetNumerator(numerator);
//	cout << "������� �����������" << endl;
//	cin >> denominator;
//	fract1.SetDenominator(denominator);
//
//	cout << "����� 2:" << endl;
//	cout << "������� ���������" << endl;
//	cin >> numerator;
//	fract2.SetNumerator(numerator);
//	cout << "������� �����������" << endl;
//	cin >> denominator;
//	fract2.SetDenominator(denominator);
//
//	// �������� ������� (+, -, *, /)
//
//	resultFract = fract1.Addition(fract2);
//	cout << "����� = " << resultFract.GetNumerator() << "/" << resultFract.GetDenominator() << endl;
//
//	resultFract = fract1.Difference(fract2);
//	cout << "�������� = " << resultFract.GetNumerator() << "/" << resultFract.GetDenominator() << endl;
//
//	resultFract = fract1.Multiplication(fract2);
//	cout << "������������ = " << resultFract.GetNumerator() << "/" << resultFract.GetDenominator() << endl;
//
//	resultFract = fract1.Degree(fract2);
//	cout << "������� = " << resultFract.GetNumerator() << "/" << resultFract.GetDenominator() << endl;
//
//	//�������� ���������� ���������� (+, -, *, /)
//
//	resultFract = fract1 + fract2;
//	cout << "����� = " << resultFract.GetNumerator() << "/" << resultFract.GetDenominator() << endl;
//
//	resultFract = fract1 - fract2;
//	cout << "�������� = " << resultFract.GetNumerator() << "/" << resultFract.GetDenominator() << endl;
//
//	resultFract = fract1 * fract2;
//	cout << "������������ = " << resultFract.GetNumerator() << "/" << resultFract.GetDenominator() << endl;
//
//	resultFract = fract1 / fract2;
//	cout << "������� = " << resultFract.GetNumerator() << "/" << resultFract.GetDenominator() << endl;
//
//
//	system("pause");
//}

//������� 2.
//�������� ����� Complex (����������� �����) ��� ����������� ��� ��������� ���� �����. �������� ������������� ������������ ���������� �������������� �������� ���
//�� ������ � ������������ �������(�������� + , -, *, / ).

//class Complex
//{
//	double realNumber;
//	double imaginaryNumber;
//	char i = 'i';
//
//public:
//
//	Complex() :Complex(0, 0)
//	{
//
//	}
//
//	Complex(double realNumber, double imaginaryNumber)
//	{
//		this->realNumber = realNumber;
//		this->imaginaryNumber = imaginaryNumber;
//	}
//
//	void SetRealNumber(double value) { realNumber = value; }
//	double GetRealNumber() { return realNumber; }
//
//	void SetImaginaryNumber(double value) { imaginaryNumber = value; }
//	double GetImaginaryNumber() { return imaginaryNumber; }
//
//	char GetI() { return i; }
//
//	Complex SummImaginaryValue(const Complex& complexNumber) const
//	{
//		Complex TempComplexNumber_1 = *this;
//		Complex TempComplexNumber_2 = complexNumber;
//
//		TempComplexNumber_1.realNumber = TempComplexNumber_1.realNumber + TempComplexNumber_2.realNumber;
//		TempComplexNumber_1.imaginaryNumber = TempComplexNumber_1.imaginaryNumber + TempComplexNumber_2.imaginaryNumber;
//
//		return TempComplexNumber_1;
//	}
//
//	Complex DifferenceImaginaryValue(const Complex& complexNumber)const
//	{
//		Complex TempComplexNumber_1 = *this;
//		Complex TempComplexNumber_2 = complexNumber;
//
//		TempComplexNumber_1.realNumber = TempComplexNumber_1.realNumber - TempComplexNumber_2.realNumber;
//		TempComplexNumber_1.imaginaryNumber = TempComplexNumber_1.imaginaryNumber - TempComplexNumber_2.imaginaryNumber;
//
//		return TempComplexNumber_1;
//	}
//
//	Complex MultiplicationImaginaryValue(const Complex& complexNumber)const
//	{
//		Complex TempComplexNumber_1 = *this;
//		Complex TempComplexNumber_2 = complexNumber;
//
//		TempComplexNumber_1.realNumber = (TempComplexNumber_1.realNumber * TempComplexNumber_2.realNumber) - (TempComplexNumber_1.imaginaryNumber * TempComplexNumber_2.imaginaryNumber);
//		TempComplexNumber_1.imaginaryNumber = (TempComplexNumber_1.imaginaryNumber * TempComplexNumber_2.realNumber) + (TempComplexNumber_1.realNumber * TempComplexNumber_2.imaginaryNumber);
//
//		return TempComplexNumber_1;
//	}
//
//	Complex DivisionImaginaryValue(const Complex& complexNumber)const
//	{
//		Complex TempComplexNumber_1 = *this;
//		Complex TempComplexNumber_2 = complexNumber;
//
//		TempComplexNumber_1.realNumber = ((TempComplexNumber_1.realNumber * TempComplexNumber_2.realNumber) + (TempComplexNumber_1.imaginaryNumber * TempComplexNumber_2.imaginaryNumber)) / (pow(TempComplexNumber_2.realNumber, 2) + pow(TempComplexNumber_2.imaginaryNumber, 2));
//		TempComplexNumber_1.imaginaryNumber = ((TempComplexNumber_1.imaginaryNumber * TempComplexNumber_2.realNumber) - (TempComplexNumber_1.realNumber * TempComplexNumber_2.imaginaryNumber)) / (pow(TempComplexNumber_2.realNumber, 2) + pow(TempComplexNumber_2.imaginaryNumber, 2));
//
//		return TempComplexNumber_1;
//	}
//
//	Complex operator+(const Complex& complexNumber)const
//	{
//		Complex TempComplexNumber_1 = *this;
//		Complex TempComplexNumber_2 = complexNumber;
//
//		TempComplexNumber_1.realNumber = TempComplexNumber_1.realNumber + TempComplexNumber_2.realNumber;
//		TempComplexNumber_1.imaginaryNumber = TempComplexNumber_1.imaginaryNumber + TempComplexNumber_2.imaginaryNumber;
//
//		return TempComplexNumber_1;
//	}
//
//	Complex operator-(const Complex& complexNumber)const
//	{
//		Complex TempComplexNumber_1 = *this;
//		Complex TempComplexNumber_2 = complexNumber;
//
//		TempComplexNumber_1.realNumber = TempComplexNumber_1.realNumber - TempComplexNumber_2.realNumber;
//		TempComplexNumber_1.imaginaryNumber = TempComplexNumber_1.imaginaryNumber - TempComplexNumber_2.imaginaryNumber;
//
//		return TempComplexNumber_1;
//	}
//
//	Complex operator*(const Complex& complexNumber)const
//	{
//		Complex TempComplexNumber_1 = *this;
//		Complex TempComplexNumber_2 = complexNumber;
//
//		TempComplexNumber_1.realNumber = (TempComplexNumber_1.realNumber * TempComplexNumber_2.realNumber) - (TempComplexNumber_1.imaginaryNumber * TempComplexNumber_2.imaginaryNumber);
//		TempComplexNumber_1.imaginaryNumber = (TempComplexNumber_1.imaginaryNumber * TempComplexNumber_2.realNumber) + (TempComplexNumber_1.realNumber * TempComplexNumber_2.imaginaryNumber);
//
//		return TempComplexNumber_1;
//	}
//
//	Complex operator/(const Complex& complexNumber)const
//	{
//		Complex TempComplexNumber_1 = *this;
//		Complex TempComplexNumber_2 = complexNumber;
//
//		TempComplexNumber_1.realNumber = ((TempComplexNumber_1.realNumber * TempComplexNumber_2.realNumber) + (TempComplexNumber_1.imaginaryNumber * TempComplexNumber_2.imaginaryNumber)) / (pow(TempComplexNumber_2.realNumber, 2) + pow(TempComplexNumber_2.imaginaryNumber, 2));
//		TempComplexNumber_1.imaginaryNumber = ((TempComplexNumber_1.imaginaryNumber * TempComplexNumber_2.realNumber) - (TempComplexNumber_1.realNumber * TempComplexNumber_2.imaginaryNumber)) / (pow(TempComplexNumber_2.realNumber, 2) + pow(TempComplexNumber_2.imaginaryNumber, 2));
//
//		return TempComplexNumber_1;
//	}
//
//	Complex operator=(const Complex& complexNumber)
//	{
//		realNumber = complexNumber.realNumber;
//		imaginaryNumber = complexNumber.imaginaryNumber;
//
//		return *this;
//	}
//};
//
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	Complex imaginaryValue_1(1,2);
//	Complex imaginaryValue_2(3,4);
//	Complex result;
//
//	// �������� �������
//
//	result = imaginaryValue_1.SummImaginaryValue(imaginaryValue_2);
//	cout << "����� ����������� ����� => " << result.GetRealNumber() << " + " << result.GetImaginaryNumber() << result.GetI() << endl;
//
//	result = imaginaryValue_1.DifferenceImaginaryValue(imaginaryValue_2);
//	cout << "�������� ����������� ����� => " << result.GetRealNumber() << " + " << result.GetImaginaryNumber() << result.GetI() << endl;
//	
//	result = imaginaryValue_1.MultiplicationImaginaryValue(imaginaryValue_2);
//	cout << "������������ ����������� ����� => " << result.GetRealNumber() << " + " << result.GetImaginaryNumber() << result.GetI() << endl;
//
//	result = imaginaryValue_1.DivisionImaginaryValue(imaginaryValue_2);
//	cout << "������� ����������� ����� => " << result.GetRealNumber() << " + " << result.GetImaginaryNumber() << result.GetI() << endl << endl;
//	
//	// �������� ���������� ����������
//
//	result = imaginaryValue_1 + imaginaryValue_2;
//	cout << "����� ����������� ����� => " << result.GetRealNumber() << " + " << result.GetImaginaryNumber() << result.GetI() << endl;
//
//	result = imaginaryValue_1 - imaginaryValue_2;
//	cout << "�������� ����������� ����� => " << result.GetRealNumber() << " + " << result.GetImaginaryNumber() << result.GetI() << endl;
//
//	result = imaginaryValue_1 * imaginaryValue_2;
//	cout << "������������ ����������� ����� => " << result.GetRealNumber() << " + " << result.GetImaginaryNumber() << result.GetI() << endl;
//
//	result = imaginaryValue_1 / imaginaryValue_2;
//	cout << "������� ����������� ����� => " << result.GetRealNumber() << " + " << result.GetImaginaryNumber() << result.GetI() << endl;
//
//	system("pause");
//}






//������� �7

// ������� 1. 
//������� ����� Overcoat (������� ������). ����������� ������������� ��������� :
//1. �������� �� ��������� ����� ������(�������� = = ).
//2. �������� ������������ ������ ������� � ������
//(�������� = ).
//3. ��������� �� ���� ���� ������ ������ ����(�������� > ).

//class Overcoat
//{
//	string type;
//	double price;
//
//public:
//
//	Overcoat() :Overcoat("Empty", 0)
//	{
//
//	}
//
//	Overcoat(string type, double price)
//	{
//		this->type = type;
//		this->price = price;
//	}
//
//	void SetType(const string& type) { this->type = type; }
//	string GetType()const { return type; }
//
//	void SetPrice(const double& price) { this->price = price; }
//	double GetPrice()const { return price; }
//
//	bool operator==(const Overcoat& clothes) const
//	{
//		return type == clothes.type;
//	}
//
//	Overcoat operator=(const Overcoat& clothes)
//	{
//		type = clothes.type;
//		price = clothes.price;
//		return *this;
//	}
//
//	int operator>(const Overcoat& clothes) const
//	{
//		if (type == clothes.type)
//		{
//			if (price != clothes.price)
//				return price > clothes.price ? 1 : -1;
//			else
//				return 0;
//		}
//		return -2;
//	}
//};
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	Overcoat clothes_1("�����", 100);
//	Overcoat clothes_2("������", 350);
//	Overcoat clothes_3("�����", 120);
//	Overcoat clothes_4("�����", 50);
//	Overcoat clothes_5("������", 100);
//	Overcoat clothes_6("������", 400);
//	Overcoat clothes_7("������", 350);
//	Overcoat clothes_8("�����", 8000);
//
//	(clothes_1 == clothes_2) ? cout << "��� ������ ����������" << endl : cout << "��� ������ ������" << endl;
//	(clothes_1 == clothes_3) ? cout << "��� ������ ����������" << endl : cout << "��� ������ ������" << endl;
//	(clothes_1 == clothes_4) ? cout << "��� ������ ����������" << endl : cout << "��� ������ ������" << endl;
//
//	cout << "������ �4 =>" << endl << "��� => " << clothes_4.GetType() << endl << "���� => " << clothes_4.GetPrice() << endl;
//
//	clothes_4 = clothes_8;
//
//	cout << "������ �4 =>" << endl << "��� => " << clothes_4.GetType() << endl << "���� => " << clothes_4.GetPrice() << endl;
//
//	int compare = clothes_2 > clothes_5;
//	cout << "��������� ��������� ������ �2 � �5 = " << compare << endl;
//	compare = clothes_2 > clothes_6;
//	cout << "��������� ��������� ������ �2 � �6 = " << compare << endl;
//	compare = clothes_2 > clothes_7;
//	cout << "��������� ��������� ������ �2 � �7 = " << compare << endl;
//
//	system("pause");
//}


//������� 2.
//������� ����� Flat (��������). ����������� ������������� ���������:
//1. �������� �� ��������� �������� ������� (��������	== ).
//2. �������� ������������ ������ ������� � ������ (�������� = ).
//3. ��������� ���� ������� �� ���� (�������� > ).

//class Flat
//{
//	double square;
//	double price;
//
//public:
//
//	Flat():Flat(0,0)
//	{
//
//	}
//
//	Flat(double square, double price)
//	{
//		this->square = square;
//		this->price = price;
//	}
//
//	void SetSquare(const double square) { this->square = square; }
//	double GetSquare() { return square; }
//
//	void SetPrice(const double price) { this->price = price; }
//	double GetPrice() { return price; }
//
//	bool operator==(const Flat& other) const
//	{
//		if (square == other.square)
//			return true;
//		return false;
//	}
//
//	Flat operator=(const Flat& other)
//	{
//		square = other.square;
//		price = other.price;
//		return *this;
//	}
//
//	int operator>(const Flat& other) const
//	{
//		if (price != other.price)
//			return price > other.price ? 1 : -1;
//		else
//			return 0;
//	}
//};
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	Flat flat_1(100, 3500000);
//	Flat flat_2(50, 3500000);
//	Flat flat_3(36, 2000000);
//	Flat flat_4(100, 20000000);
//	Flat flat_5(300, 100);
//
//	(flat_1 == flat_2) ? cout << "������� ������� ���������" << endl : cout << "������� ������� ������" << endl;
//	(flat_1 == flat_3) ? cout << "������� ������� ���������" << endl : cout << "������� ������� ������" << endl;
//	(flat_1 == flat_4) ? cout << "������� ������� ���������" << endl << endl : cout << "������� ������� ������" << endl << endl;
//
//	cout << "�������� �3 =>" << endl << "������� => " << flat_3.GetSquare() << endl << "���� => " << flat_3.GetPrice() << endl << endl;
//
//	flat_3 = flat_5;
//
//	cout << "�������� �3 =>" << endl << "������� => " << flat_3.GetSquare() << endl << "���� => " << flat_3.GetPrice() << endl << endl;
//
//	int compare = flat_1 > flat_2;
//	cout << "��������� ��������� ������� �1 � �2 = " << compare << endl;
//	compare = flat_1 > flat_3;
//	cout << "��������� ��������� ������� �1 � �3 = " << compare << endl;
//	compare = flat_1 > flat_4;
//	cout << "��������� ��������� ������� �1 � �4 = " << compare << endl;
//	compare = flat_1 > flat_5;
//	cout << "��������� ��������� ������� �1 � �5 = " << compare << endl;
//
//	system("pause");
//}




//������� �8

//������� 1.
//�������� � ��� ������������ ����� String ����������� ��������.
//
//������� 2.
//�������� � ��� ������������ ����� Array ����������� ��������.

//class MyString
//{
//	int length;
//	char* str;
//
//public:
//	MyString() : MyString("")
//	{
//	}
//
//	MyString(const char* str)
//	{
//		length = strlen(str);
//		this->str = new char[length + 1];
//		strcpy_s(this->str, length + 1, str);
//	}
//
//	MyString(const MyString& other)
//	{
//		length = other.length;
//		str = new char[length + 1];
//		strcpy_s(str, length + 1, other.str);
//	}
//
//	MyString(MyString&& other)
//	{
//		length = other.length;
//		str = other.str;
//
//		other.str = nullptr;
//		other.length = 0;
//	}
//
//	~MyString()
//	{
//		delete[] str;
//	}
//
//	char* GetStr()
//	{
//		return str;
//	}
//
//	MyString operator+(const MyString& other)
//	{
//		int NewLength = length + other.length + 2;
//		char* NewStr = new char[NewLength];
//		strcpy_s(NewStr, NewLength, str);
//		strcat_s(NewStr, NewLength, other.str);
//		delete[]str;
//		str = NewStr;
//		length = NewLength;
//		return *this;
//	}
//
//	MyString operator=(const MyString& other)
//	{
//		length = other.length;
//		str = new char[length + 1];
//		strcpy_s(str, length, other.str);
//		return *this;
//	}
//
//	MyString operator=(MyString&& other)
//	{
//		length = other.length;
//		str = other.str;
//
//		other.str = nullptr;
//		other.length = 0;
//
//		return *this;
//	}
//
//};
//
//class Array
//{
//	int size;
//	int* arr;
//
//	static void FixSize(int& size)
//	{
//		if (size < 0)
//			size = 0;
//	}
//
//	static int GetRandomValue(int startRange, int endRange)
//	{
//		return rand() % (endRange - startRange + 1) + startRange;
//	}
//
//public:
//	Array()
//	{
//		size = 0;
//		arr = nullptr;
//	}
//
//	explicit Array(int size) : Array(size, 0)
//	{
//	}
//
//	Array(int size, int value)
//	{
//		FixSize(size);
//
//		this->size = size;
//		arr = new int[size];
//		for (int i = 0; i < size; i++)
//			arr[i] = value;
//	}
//
//	Array(int* arr, int size)
//	{
//		FixSize(size);
//
//		this->size = size;
//		this->arr = new int[size];
//		for (int i = 0; i < size; i++)
//			this->arr[i] = arr[i];
//	}
//
//	Array(const Array& other)
//	{
//		size = other.size;
//		arr = new int[size];
//		for (int i = 0; i < size; i++)
//			arr[i] = other.arr[i];
//	}
//	
//	Array(Array&& other)
//	{
//		size = other.size;
//		arr = other.arr;
//
//		other.size = 0;
//		other.arr = nullptr;
//	}
//
//	~Array()
//	{
//		if (arr != nullptr)
//			delete[] arr;
//	}
//
//	int Size() const
//	{
//		return size;
//	}
//
//	int& At(const int index)
//	{
//		return arr[index];
//	}
//
//	int At(const int index) const
//	{
//		return arr[index];
//	}
//
//	bool IsEmpty() const
//	{
//		return size == 0;
//	}
//
//	void Clear()
//	{
//		size = 0;
//
//		if (arr != nullptr)
//			delete[] arr;
//
//		arr = nullptr;
//	}
//
//	void Resize(int size)
//	{
//		FixSize(size);
//
//		int* newArr = size == 0 ? nullptr : new int[size];
//		int minSize = min(this->size, size);
//		for (int i = 0; i < minSize; i++)
//			newArr[i] = arr[i];
//		for (int i = minSize; i < size; i++)
//			newArr[i] = 0;
//
//		if (arr != nullptr)
//			delete[] arr;
//
//		this->size = size;
//		arr = newArr;
//	}
//
//	void Randomize(int startRange, int endRange)
//	{
//		if (IsEmpty())
//			return;
//
//		for (int i = 0; i < size; i++)
//			arr[i] = GetRandomValue(startRange, endRange);
//	}
//
//	void Sort(bool desc = false)
//	{
//		if (IsEmpty())
//			return;
//
//		if (desc)
//			sort(arr, arr + size, [](int& a, int& b) { return a > b; });
//		else
//			sort(arr, arr + size, [](int& a, int& b) { return a < b; });
//	}
//
//	void Swap(int firstIndex, int secondIndex)
//	{
//		swap(arr[firstIndex], arr[secondIndex]);
//	}
//
//	void Concatenate(const Array& other)
//	{
//		if (other.IsEmpty())
//			return;
//
//		int newSize = size + other.size;
//		int* newArr = new int[newSize];
//		for (int i = 0; i < size; i++)
//			newArr[i] = arr[i];
//		for (int i = 0; i < other.size; i++)
//			newArr[size + i] = other.arr[i];
//
//		if (arr != nullptr)
//			delete[] arr;
//
//		this->size = newSize;
//		arr = newArr;
//	}
//
//	void Insert(int index, int value)
//	{
//		int newSize = size + 1;
//		int* newArr = new int[newSize];
//		for (int i = 0; i < index; i++)
//			newArr[i] = arr[i];
//		newArr[index] = value;
//		for (int i = index; i < size; i++)
//			newArr[i + 1] = arr[i];
//
//		if (arr != nullptr)
//			delete[] arr;
//
//		this->size = newSize;
//		arr = newArr;
//	}
//
//	void InsertFront(int value)
//	{
//		Insert(0, value);
//	}
//
//	void InsertBack(int value)
//	{
//		Insert(size, value);
//	}
//
//	void Remove(int index)
//	{
//		if (size <= 1)
//		{
//			Clear();
//			return;
//		}
//
//		int newSize = size - 1;
//		int* newArr = new int[newSize];
//		for (int i = 0; i < index; i++)
//			newArr[i] = arr[i];
//		for (int i = index; i < newSize; i++)
//			newArr[i] = arr[i + 1];
//
//		if (arr != nullptr)
//			delete[] arr;
//
//		this->size = newSize;
//		arr = newArr;
//	}
//
//	void RemoveFront()
//	{
//		Remove(0);
//	}
//
//	void RemoveBack()
//	{
//		Remove(size - 1);
//	}
//
//	void Replace(int oldValue, int newValue)
//	{
//		for (int i = 0; i < size; i++)
//			if (arr[i] == oldValue)
//				arr[i] = newValue;
//	}
//
//	double GetAverage() const
//	{
//		if (IsEmpty())
//			return 0;
//
//		int sum = 0;
//		for (int x : span(arr, arr + size))
//			sum += x;
//
//		return (double)sum / size;
//	}
//
//	int GetSum() const
//	{
//		int sum = 0;
//		for (int x : span(arr, arr + size))
//			sum += x;
//
//		return sum;
//	}
//
//	int GetMin() const
//	{
//		if (IsEmpty())
//			return 0;
//
//		int min = arr[0];
//		for (int x : span(arr, arr + size))
//			if (x < min)
//				min = x;
//
//		return min;
//	}
//
//	int GetMax() const
//	{
//		if (IsEmpty())
//			return 0;
//
//		int max = arr[0];
//		for (int x : span(arr, arr + size))
//			if (x > max)
//				max = x;
//
//		return max;
//	}
//
//	int Find(int value) const
//	{
//		for (int i = 0; i < size; i++)
//			if (arr[i] == value)
//				return i;
//
//		return -1;
//	}
//
//	int FindLast(int value) const
//	{
//		for (int i = size - 1; i >= 0; i--)
//			if (arr[i] == value)
//				return i;
//
//		return -1;
//	}
//
//	string ToString() const
//	{
//		return ToString(", ");
//	}
//
//	string ToString(string separator) const
//	{
//		if (IsEmpty())
//			return "";
//
//		string str = to_string(arr[0]);
//		for (int x : span(arr + 1, arr + size))
//			str += separator + to_string(x);
//
//		return str;
//	}
//};
//
//void F1(Array arr)
//{
//	cout << "arr = [" << arr.ToString() << "] with size = " << arr.Size() << endl;
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	MyString str1;
//	MyString str2 = "Qwerty";
//	MyString str3 = "Hello, World!";
//	MyString str4 = str2;
//	MyString str5 = str2+str3;
//
//	cout << "str1 = " << str1.GetStr() << endl;
//	cout << "str2 = " << str2.GetStr() << endl;
//	cout << "str3 = " << str3.GetStr() << endl;
//	cout << "str4 = " << str4.GetStr() << endl;
//	cout << "str5 = " << str5.GetStr() << endl;
//
//
//	Array arr2(4);
//	Array arr3(5, 777);
//	Array arr4(arr3);
//	Array arr1 = arr2; 
//	
//
//	cout << "arr1 = [" << arr1.ToString() << "] with size = " << arr1.Size() << endl;
//	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;
//	cout << "arr3 = [" << arr3.ToString() << "] with size = " << arr3.Size() << endl;
//	cout << "arr4 = [" << arr4.ToString() << "] with size = " << arr4.Size() << endl;
//
//
//
//	system("pause");
//}

//������� �9
//
//������� 1.
//� ����� ��������� ����� String �������� ���������� [], (),
//�������������� ���� � int:
//[] � ���������� ������� �� ���������� �������;
//() � ���� ������ � ������, ���� ������ ���� ���������� ������, ���� ��� �1.
//�������������� � int ���������� ����� ������.

class MyString
{
	int length;
	char* str;

public:
	MyString() : MyString("")
	{
	}

	MyString(const char* str)
	{
		length = strlen(str);
		this->str = new char[length + 1];
		strcpy_s(this->str, length + 1, str);
	}

	MyString(const MyString& other)
	{
		length = other.length;
		str = new char[length + 1];
		strcpy_s(str, length + 1, other.str);
	}

	MyString(MyString&& other)
	{
		length = other.length;
		str = other.str;

		other.str = nullptr;
		other.length = 0;
	}

	~MyString()
	{
		delete[] str;
	}

	char* GetStr()
	{
		return str;
	}

	MyString operator+(const MyString& other)
	{
		int NewLength = length + other.length + 2;
		char* NewStr = new char[NewLength];
		strcpy_s(NewStr, NewLength, str);
		strcat_s(NewStr, NewLength, other.str);
		delete[]str;
		str = NewStr;
		length = NewLength;
		return *this;
	}

	MyString operator=(const MyString& other)
	{
		length = other.length;
		str = new char[length + 1];
		strcpy_s(str, length, other.str);
		return *this;
	}

	MyString operator=(MyString&& other)
	{
		if (&other == nullptr)
			return *this;

		length = other.length;
		str = other.str;

		other.str = nullptr;
		other.length = 0;

		return *this;
	}

	char operator[](const int index) const
	{
		return str[index];
	}

	int operator()(const char symbol) const
	{
		for (int i = 0; str[i] != '\0'; i++)
			if (str[i] == symbol)
				return i;
		return -1;
	}

	int()
	{

	}
};

void main()
{
	setlocale(LC_ALL, "ru");

	MyString str1 = "Qwerty";

	cout << "str1 = " << str1.GetStr() << endl;
	cout << "���������� [] - " << str1[2] << endl;
	cout << "���������� () - " << str1('t') << endl;

	system("pause");
}
