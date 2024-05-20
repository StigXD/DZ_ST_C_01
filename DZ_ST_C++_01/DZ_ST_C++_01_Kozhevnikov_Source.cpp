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
//public:
//	Fraction() : Fraction(0, 1)
//	{
//
//	}
//
//	Fraction(int numerator, int denominator)
//	{
//		Fraction::numerator = numerator;
//		Fraction::denominator = denominator;
//	}
//	void SetNumerator(int value) { numerator = value; }
//	int GetNumerator() { return numerator; }
//
//	void SetDenominator(int value) { denominator = value; }
//	int GetDenominator() { return denominator; }
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
//	void CommonDenominator(Fraction& fract, int nod)
//	{
//		nod /= fract.denominator;
//		fract.numerator *= nod;
//		fract.denominator *= nod;
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
//	void Addition(Fraction& fract1, Fraction& fract2, Fraction& result)
//	{
//		int nok = FindNok(fract1.denominator, fract2.denominator);
//
//		CommonDenominator(fract1, nok);
//		CommonDenominator(fract2, nok);
//
//		result.numerator = abs(fract1.numerator + fract2.numerator);
//		result.denominator = fract1.denominator;
//
//		Reduction(result);
//	}
//
//	void Difference(Fraction& fract1, Fraction& fract2, Fraction& result)
//	{
//		int nok = FindNok(fract1.denominator, fract2.denominator);
//
//		CommonDenominator(fract1, nok);
//		CommonDenominator(fract2, nok);
//
//		result.numerator = fract1.numerator - fract2.numerator;
//		result.denominator = fract1.denominator;
//
//		Reduction(result);
//	}
//
//	void Multiplication(Fraction& fract1, Fraction& fract2, Fraction& result)
//	{
//		int nok = FindNok(fract1.denominator, fract2.denominator);
//
//		CommonDenominator(fract1, nok);
//		CommonDenominator(fract2, nok);
//
//		result.numerator = fract1.numerator * fract2.numerator;
//		result.denominator = fract1.denominator * fract2.denominator;
//
//		Reduction(result);
//	}
//
//	void Degree(Fraction& fract1, Fraction& fract2, Fraction& result)
//	{
//		int nok = FindNok(fract1.denominator, fract2.denominator);
//
//		CommonDenominator(fract1, nok);
//		CommonDenominator(fract2, nok);
//
//		result.numerator = fract1.numerator * fract2.denominator;
//		result.denominator = fract1.denominator * fract2.numerator;
//
//		Reduction(result);
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
//	resultFract.Addition(fract1, fract2, resultFract);
//	cout << "����� = " << resultFract.GetNumerator() << "/" << resultFract.GetDenominator() << endl;
//
//	resultFract.Difference(fract1, fract2, resultFract);
//	cout << "�������� = " << resultFract.GetNumerator() << "/" << resultFract.GetDenominator() << endl;
//
//	resultFract.Multiplication(fract1, fract2, resultFract);
//	cout << "������������ = " << resultFract.GetNumerator() << "/" << resultFract.GetDenominator() << endl;
//
//	resultFract.Degree(fract1, fract2, resultFract);
//	cout << "������� = " << resultFract.GetNumerator() << "/" << resultFract.GetDenominator() << endl;
//
//	system("pause");
//}

//������� �2. �������� ���������� "���������� �����". ���������� ������� ������ �� �������� (���, �������� �������, ������� �������, ��������� �������,
//�������������� ���������� � ��������) ������ ���������������� ������. ��������� ����� ����������� - �������, ��������� - �������, ��������������,
//inline - ��������� - �������, ����������� ��������������, ���������� ����������.
//����������� ���������� �������� ����������� ������ ��� ���. ������������ ������������ ����������� ��������� ����� ���������, ������� ���������,
//������ ��������� �� ���, ���������� ���� ���������, ��������� ���������� � ���� � ��������� �� �����.

class Abonent
{
	char* fio;
	long long homePhone;
	long long workPhone;
	long long mobilPhone;
	char* additionally;
	
public:

	Abonent() : Abonent(nullptr, 0, 0, 0, nullptr) {}

	Abonent(const char* fio, long long homePhone, long long workPhone, long long mobilPhone) : Abonent(fio, homePhone, workPhone, mobilPhone, nullptr)	{}

	Abonent(const char* fio, long long homePhone, long long workPhone) : Abonent (fio, homePhone, workPhone, 0, nullptr)	{}

	Abonent(const char* fio, long long homePhone) : Abonent(fio, homePhone, 0, 0, nullptr)	{}

	Abonent(const char* fio) : Abonent(fio, 0, 0, 0, nullptr) {}

	Abonent(const char* fio, long long homePhone, long long workPhone, long long mobilPhone, const char* additionally)
	{
		if(fio!=nullptr)
		{
			int size = strlen(fio) + 1;
			this->fio = new char[size];
			strcpy_s(this->fio, size, fio);
		}
		else
			this->fio = nullptr;

		if (additionally != nullptr)
		{
			int size = strlen(additionally) + 1;
			this->additionally = new char[size];
			strcpy_s(this->additionally, size, additionally);
		}
		else
			this->additionally = nullptr;

		this->homePhone = homePhone;
		this->workPhone = workPhone;
		this->mobilPhone = mobilPhone;
	}

	Abonent(const Abonent& other)
	{
		if (other.fio != nullptr)
		{
			int size = strlen(other.fio);
			this->fio = new char[size];
			strcpy_s(this->fio, size, other.fio);
		}
		else
			this->fio = fio;
		if (other.additionally != nullptr)
		{
			int size = strlen(other.additionally);
			this->additionally = new char[size];
			strcpy_s(this->additionally, size, other.additionally);
		}
		else
			this->additionally = additionally;

		homePhone = other.homePhone;
		workPhone = other.workPhone;
		mobilPhone = other.mobilPhone;
	}

	~Abonent()
	{
		if(fio!=nullptr)
			delete[] fio;
		if (additionally != nullptr)
			delete[] additionally;
	}

	void SetFio (char* newFio)
	{
		int size = strlen(newFio) + 1;
		char* fio = new char[size+1];
		strcpy_s(fio, size, newFio);
		delete[] fio;
	}

	const char* GetFio() { return fio; }

	void SetHomePhone(long long homePhone)	{this->homePhone = homePhone;}
	long long GetHomePhone() { return homePhone; }

	void SetWorkPhone(long long workPhone)	{this->workPhone = workPhone;}
	long long GetWorkPhone() { return workPhone; }

	void SetMobilPhone(long long mobilPhone)  {this->mobilPhone = mobilPhone;}
	long long GetMobilPhone() { return mobilPhone; }

	void SetAdditionally(char* newAdditionally)
	{
		int size = strlen(newAdditionally) + 1;
		char* additionally = new char[size + 1];
		strcpy_s(additionally, size, newAdditionally);
		delete[] additionally;
	}
	const char* GetAdditionally() { return additionally; }
};

class AbonentBase
{
	vector <Abonent> abonentBase;

public:
	
	AbonentBase()
	{ 
		Abonent abonent;
		abonentBase.push_back(abonent);
	}
	
	int Size()	{return abonentBase.size();}

	void FillAbonentBase()
	{
		const int size = 128;
		if (abonentBase.front().GetFio() == nullptr)
			abonentBase.pop_back();

		Abonent abonent;
		char fio[size];
		cout << "������� ��� ��������" << endl;
		cin.ignore();
		abonent.SetFio(gets_s(fio, size));

		cout << "������� �������� �����" << endl;
		long long homePhone;
		cin >> homePhone;
		abonent.SetHomePhone(homePhone);

		cout << "������� ������� �����" << endl;
		long long workPhone;
		cin >> workPhone;
		abonent.SetWorkPhone(workPhone);

		cout << "������� ��������� �����" << endl;
		long long mobilPhone;
		cin >> mobilPhone;
		abonent.SetMobilPhone(mobilPhone);

		char additionally[size];
		cout << "������� ���. ����������" << endl;
		cin.ignore();
		abonent.SetAdditionally(gets_s(additionally, size));

		abonentBase.push_back(abonent);
	}
	
	int ShowAbonentBase(int i)
	{
		if (abonentBase.at(i).GetFio() == nullptr)
			return -1;
		else
		{
			cout << "������� " << i + 1 << endl;
			cout << "���: " << abonentBase.at(i).GetFio() << endl;
			cout << "�������� �����: " << abonentBase.at(i).GetHomePhone() << endl;
			cout << "������� �����: " << abonentBase.at(i).GetWorkPhone() << endl;
			cout << "��������� �����: " << abonentBase.at(i).GetMobilPhone() << endl;
			cout << "���. ����������: " << abonentBase.at(i).GetAdditionally() << endl << endl;
		}
	}
	int FindAbonent(const char* fio)
	{
		if (abonentBase.front().GetFio() == nullptr)
			return -1;

		for (int i = 0; i < abonentBase.size(); i++)
			if (strcmp(abonentBase.at(i).GetFio(), fio) == 0)
				return(i);
		return -1;

	}

	int CopyAbonent(int abonentNumber)
	{
		if (abonentBase.size() < abonentNumber)
			return -1;
		abonentBase.push_back(abonentBase.at(abonentNumber));
	}

	int DeleteAbonent(int abonentNumber)
	{
		if (abonentBase.size() < abonentNumber)
			return -1;

		abonentBase.erase(abonentBase.begin() + abonentNumber);

		if(abonentBase.empty())
		{
			Abonent abonent;
			abonentBase.push_back(abonent);
		}
	}
};

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	AbonentBase abonentBase;

	int choice;
	while (true)
	{
		cout << "����" << endl << endl << endl;
		cout << "�������� ��������: " << endl;
		cout << "1 - �������� ���� ���������" << endl;
		cout << "2 - �������� ��������" << endl;
		cout << "3 - ����� ���������� �� ��������" << endl;
		cout << "4 - ������� ��������" << endl;
		cout << "5 - ���������� ������ ��������" << endl;
		cout << "0 - �����" << endl;

		cin >> choice;

		if (choice == 0)
			return;

		switch (choice)
		{
		case 1:
		{
			for (int i = 0; i < abonentBase.Size(); i++)
				if(abonentBase.ShowAbonentBase(i)==-1)
				{
					cout << "������� " << i + 1 << endl;
					cout << "��� ������" << endl;
					continue;
				}
			break;
		}
		case 2:
		{
			abonentBase.FillAbonentBase();
			break;
		}
		case 3:
		{
			cout << "������� ��� ��������" << endl;
			const int size = 128;
			char abonentName[size];
			cin.ignore();
			int resultFind = abonentBase.FindAbonent(gets_s(abonentName, size));
			if (resultFind == -1)
				cout << "���������� ���!" << endl;
			else
				abonentBase.ShowAbonentBase(resultFind);
			break;
		}
		case 4:
		{
			cout << "������� ����� �������� ��� ��������" << endl;
			int deleteNumber;
			cin >> deleteNumber;
			int deleteResult = abonentBase.DeleteAbonent(deleteNumber-1);
			if (deleteResult == -1)
				cout << "������ ��������. �������� ����� ��������." << endl;
			break;
		}
		case 5:
		{
			cout << "������� ����� �������� ��� �����������" << endl;
			int copyNumber;
			cin >> copyNumber;
			int copyResult = abonentBase.CopyAbonent(copyNumber - 1);
			if (copyResult == -1)
				cout << "������ ��������. �������� ����� ��������." << endl;
			break;
		}

		}
		system("pause");
		system("cls");
	}
	system("pause");
}