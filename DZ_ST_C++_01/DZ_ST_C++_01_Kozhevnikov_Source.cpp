#include <iostream>
#include <vector>
#include <Windows.h>
#include <stdio.h>
#include <span>
using namespace std;

//������� �1. ���������� ����� �����.���������� ������� ��������� � ����������� � �������� ���������� - ������. ���������� ������� - ����� ��� ����� ������
//� ���������� - �����, ��� ���������� �������������� �������� (��������, ���������, ���������, �������, � �.�.).

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
//	void Reduction(Fraction& fract)
//	{
//		int nod = FindNod(fract.numerator, fract.denominator);
//		if (nod > 1)
//		{
//			fract.numerator /= nod;
//			fract.denominator /= nod;
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
//	void SetNumerator(int value) { numerator = value; }
//	int GetNumerator() { return numerator; }
//
//	void SetDenominator(int value) { denominator = value; }
//	int GetDenominator() { return denominator; }
//
//	Fraction Addition(const Fraction& fract2)
//	{
//		Fraction tempA = *this;
//		Fraction tempB = fract2;
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
//		Reduction(tempA);
//		return tempA;
//	}
//
//	Fraction Difference(Fraction& fract2)
//	{
//		Fraction tempA = *this;
//		Fraction tempB = fract2;
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
//		Reduction(tempA);
//
//		return tempA;
//	}
//
//	Fraction Multiplication(Fraction& fract2)
//	{
//		Fraction tempA = *this;
//		Fraction tempB = fract2;
//		
//		tempA.numerator *= tempB.numerator;
//		tempA.denominator *= tempB.denominator;
//
//		Reduction(tempA);
//
//		return tempA;
//	}
//
//	Fraction Degree(Fraction& fract2)
//	{
//		Fraction tempA = *this;
//		Fraction tempB = fract2;
//		
//		tempA.numerator *= tempB.denominator;
//		tempA.denominator *= tempB.numerator;
//
//		Reduction(tempA);
//
//		return tempA;
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
//	system("pause");
//}

//������� �2. �������� ���������� "���������� �����". ���������� ������� ������ �� �������� (���, �������� �������, ������� �������, ��������� �������,
//�������������� ���������� � ��������) ������ ���������������� ������. ��������� ����� ����������� - �������, ��������� - �������, ��������������,
//inline - ��������� - �������, ����������� ��������������, ���������� ����������.
//����������� ���������� �������� ����������� ������ ��� ���. ������������ ������������ ����������� ��������� ����� ���������, ������� ���������,
//������ ��������� �� ���, ���������� ���� ���������, ��������� ���������� � ���� � ��������� �� �����.

//class Abonent
//{
//	char* fio;
//	long long homePhone; // ������ ����� ��� ����� ������������ string ��� char[]
//	long long workPhone; // ������ ����� ��� ����� ������������ string ��� char[]
//	long long mobilPhone; // ������ ����� ��� ����� ������������ string ��� char[]
//	char* additionally;
//	
//public:
//
//	Abonent() : Abonent(nullptr, 0, 0, 0, nullptr) {}
//
//	Abonent(const char* fio, long long homePhone, long long workPhone, long long mobilPhone) : Abonent(fio, homePhone, workPhone, mobilPhone, nullptr)	{}
//
//	Abonent(const char* fio, long long homePhone, long long workPhone) : Abonent (fio, homePhone, workPhone, 0, nullptr)	{}
//
//	Abonent(const char* fio, long long homePhone) : Abonent(fio, homePhone, 0, 0, nullptr)	{}
//
//	Abonent(const char* fio) : Abonent(fio, 0, 0, 0, nullptr) {}
//
//	Abonent(const char* fio, long long homePhone, long long workPhone, long long mobilPhone, const char* additionally)
//	{
//		if(fio!=nullptr)
//		{
//			int size = strlen(fio) + 1;
//			this->fio = new char[size];
//			strcpy_s(this->fio, size, fio);
//		}
//		else
//			this->fio = nullptr;
//
//		if (additionally != nullptr)
//		{
//			int size = strlen(additionally) + 1;
//			this->additionally = new char[size];
//			strcpy_s(this->additionally, size, additionally);
//		}
//		else
//			this->additionally = nullptr;
//
//		this->homePhone = homePhone;
//		this->workPhone = workPhone;
//		this->mobilPhone = mobilPhone;
//	}
//
//	Abonent(const Abonent& other)
//	{
//		if (other.fio != nullptr)
//		{
//			int size = strlen(other.fio)+1;
//			this->fio = new char[size];
//			strcpy_s(this->fio, size, other.fio);
//		}
//		else
//			this->fio = nullptr;
//
//		if (other.additionally != nullptr)
//		{
//			int size = strlen(other.additionally)+1;
//			this->additionally = new char[size];
//			strcpy_s(this->additionally, size, other.additionally);
//		}
//		else
//			this->additionally = nullptr;
//
//		homePhone = other.homePhone;
//		workPhone = other.workPhone;
//		mobilPhone = other.mobilPhone;
//	}
//
//	~Abonent()
//	{
//		if(fio!=nullptr)
//			delete[] fio;
//		if (additionally != nullptr)
//			delete[] additionally;
//	}
//
//	Abonent operator=(const Abonent& other)
//	{
//		if (other.fio != nullptr)
//		{
//			int size = strlen(other.fio) + 1;
//			this->fio = new char[size];
//			strcpy_s(this->fio, size, other.fio);
//		}
//		else
//			this->fio = nullptr;
//
//		if (other.additionally != nullptr)
//		{
//			int size = strlen(other.additionally) + 1;
//			this->additionally = new char[size];
//			strcpy_s(this->additionally, size, other.additionally);
//		}
//		else
//			this->additionally = nullptr;
//
//		homePhone = other.homePhone;
//		workPhone = other.workPhone;
//		mobilPhone = other.mobilPhone;
//
//		return *this;
//	}
//
//	void SetFio (char* fio)
//	{
//		int size = strlen(fio) + 1;
//		this-> fio = new char[size];
//		strcpy_s(this->fio, size, fio);
//	}
//
//	const char* GetFio() { return fio; }
//
//	void SetHomePhone(long long homePhone)	{this->homePhone = homePhone;}
//	long long GetHomePhone() { return homePhone; }
//
//	void SetWorkPhone(long long workPhone)	{this->workPhone = workPhone;}
//	long long GetWorkPhone() { return workPhone; }
//
//	void SetMobilPhone(long long mobilPhone)  {this->mobilPhone = mobilPhone;}
//	long long GetMobilPhone() { return mobilPhone; }
//
//	void SetAdditionally(char* additionally)
//	{
//		int size = strlen(additionally) + 1;
//		this ->additionally = new char[size];
//		strcpy_s(this->additionally, size, additionally);
//	}
//	const char* GetAdditionally() { return additionally; }
//};
//
//class AbonentBase
//{
//	vector <Abonent> abonentBase;
//
//public:
//	
//	AbonentBase()
//	{ 
//		Abonent abonent;
//		abonentBase.push_back(abonent);
//	}
//
//	int Size()	{return abonentBase.size();}
//
//	void FillAbonentBase()
//	{
//		const int size = 128;
//		if (abonentBase.front().GetFio() == nullptr)
//			abonentBase.pop_back();
//
//		Abonent abonent;
//		char fio[size];
//		cout << "������� ��� ��������" << endl;
//		cin.ignore();
//		abonent.SetFio(gets_s(fio, size));
//
//		cout << "������� �������� �����" << endl;
//		long long homePhone;
//		cin >> homePhone;
//		abonent.SetHomePhone(homePhone);
//
//		cout << "������� ������� �����" << endl;
//		long long workPhone;
//		cin >> workPhone;
//		abonent.SetWorkPhone(workPhone);
//
//		cout << "������� ��������� �����" << endl;
//		long long mobilPhone;
//		cin >> mobilPhone;
//		abonent.SetMobilPhone(mobilPhone);
//
//		char additionally[size];
//		cout << "������� ���. ����������" << endl;
//		cin.ignore();
//		abonent.SetAdditionally(gets_s(additionally, size));
//
//		abonentBase.push_back(abonent);
//	}
//	
//	int ShowAbonentBase(int i)
//	{
//		if (abonentBase.at(i).GetFio() == nullptr)
//			return -1;
//		else
//		{
//			cout << "������� " << i + 1 << endl;
//			cout << "���: " << abonentBase.at(i).GetFio() << endl;
//			cout << "�������� �����: " << abonentBase.at(i).GetHomePhone() << endl;
//			cout << "������� �����: " << abonentBase.at(i).GetWorkPhone() << endl;
//			cout << "��������� �����: " << abonentBase.at(i).GetMobilPhone() << endl;
//			cout << "���. ����������: " << abonentBase.at(i).GetAdditionally() << endl << endl;
//		}
//	}
//	int FindAbonent(const char* fio)
//	{
//		if (abonentBase.front().GetFio() == nullptr)
//			return -1;
//
//		for (int i = 0; i < abonentBase.size(); i++)
//			if (strcmp(abonentBase.at(i).GetFio(), fio) == 0)
//				return(i);
//		return -1;
//
//	}
//
//	int CopyAbonent(int abonentNumber)
//	{
//		if (abonentBase.size() < abonentNumber)
//			return -1;
//		abonentBase.push_back(abonentBase.at(abonentNumber));
//	}
//
//	int DeleteAbonent(int abonentNumber)
//	{
//		if (abonentBase.size() < abonentNumber)
//			return -1;
//
//		for (int i = abonentNumber; i < abonentBase.size()-1; i++)
//			abonentBase[i] = abonentBase[i+1];
//		abonentBase.pop_back();
//
//		if(abonentBase.empty())
//		{
//			Abonent abonent;
//			abonentBase.push_back(abonent);
//		}
//	}
//};
//
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	AbonentBase abonentBase;
//
//	int choice;
//	while (true)
//	{
//		cout << "����" << endl << endl << endl;
//		cout << "�������� ��������: " << endl;
//		cout << "1 - �������� ���� ���������" << endl;
//		cout << "2 - �������� ��������" << endl;
//		cout << "3 - ����� ���������� �� ��������" << endl;
//		cout << "4 - ������� ��������" << endl;
//		cout << "5 - ���������� ������ ��������" << endl;
//		cout << "0 - �����" << endl;
//
//		cin >> choice;
//
//		if (choice == 0)
//			return;
//
//		switch (choice)
//		{
//		case 1:
//		{
//			for (int i = 0; i < abonentBase.Size(); i++)
//				if(abonentBase.ShowAbonentBase(i)==-1)
//				{
//					cout << "������� " << i + 1 << endl;
//					cout << "��� ������" << endl;
//					continue;
//				}
//			break;
//		}
//		case 2:
//		{
//			abonentBase.FillAbonentBase();
//			break;
//		}
//		case 3:
//		{
//			cout << "������� ��� ��������" << endl;
//			const int size = 128;
//			char abonentName[size];
//			cin.ignore();
//			int resultFind = abonentBase.FindAbonent(gets_s(abonentName, size));
//			if (resultFind == -1)
//				cout << "���������� ���!" << endl;
//			else
//				abonentBase.ShowAbonentBase(resultFind);
//			break;
//		}
//		case 4:
//		{
//			cout << "������� ����� �������� ��� ��������" << endl;
//			int deleteNumber;
//			cin >> deleteNumber;
//			int deleteResult = abonentBase.DeleteAbonent(deleteNumber-1);
//			if (deleteResult == -1)
//				cout << "������ ��������. �������� ����� ��������." << endl;
//			break;
//		}
//		case 5:
//		{
//			cout << "������� ����� �������� ��� �����������" << endl;
//			int copyNumber;
//			cin >> copyNumber;
//			int copyResult = abonentBase.CopyAbonent(copyNumber - 1);
//			if (copyResult == -1)
//				cout << "������ ��������. �������� ����� ��������." << endl;
//			break;
//		}
//
//		}
//		system("pause");
//		system("cls");
//	}
//	system("pause");
//}

//������� �3. ����������� ����� String, ������� � ���������� ����� �������������� ��� ������ �� ��������. ����� ������ ��������� :
//- ����������� �� ���������, ����������� ������� ������ ������ 80 ��������;
//- �����������, ����������� ��������� ������ ������������� �������;
//- �����������, ������� ������ ������ � �������������� � �������, ���������� �� ������������.
// 
//���������� ������� ����������, � ����� ������������ ��������� ������������� �������������, ���� ��� ��������.
//����� ������ ��������� ������ ��� ����� ����� � ���������� � ������ ����� �� �����. ����� ����� ����������� ����������� ������� - ����, ������� ����� ����������
//���������� ��������� �������� �����.

class String
{
	char* str;
	int size;

	static inline int countPrivate = 0;

public:

	static inline int countPublic = 0;

	String():String(80)
	{

	}

	String(const int size)
	{
		this->size = size;
		str = new char[size];
		countPublic++;
		countPrivate++;
	}

	String(const char* str)
	{
		size = strlen(str) + 1;
		this->str = new char[size];
		strcpy_s(this->str, size, str);
		countPublic++;
		countPrivate++;
	}

	~String()
	{
		if (str != nullptr)
			delete[] str;
	}

	const char* GetStr() { return str; }

	void SetStr(const char* str)
	{
		size = strlen(str) + 1;
		this->str = new char[size];
		strcpy_s(this->str, size, str);
	}

	void InputStr()
	{
		const int size = 64;
		char str[size];
		cout << "������� ������" << endl;
		SetStr(gets_s(str, size));
	}

	void OutputStr()
	{
		for (int i = 0; str[i] != '\0'; i++)
			cout << str[i];
		cout << endl;
	}

	static void PrintCount()
	{
		cout << "������� " << countPrivate << " ����� (countPrivate)" << endl;
	}
};

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	String str1;
	str1.OutputStr();

	String str2(24);
	str2.OutputStr();

	String str3 = "Hello, world";
	str3.OutputStr();

	String str4;
	str4.InputStr();
	str4.OutputStr();

	cout<< "������� " << String::countPublic << " ����� (countPublic)" << endl;

	String::PrintCount();

	system("pause");
}