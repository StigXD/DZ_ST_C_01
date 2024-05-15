#include <iostream>
#include <vector>
#include <Windows.h>
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
	const char* fio;
	int homePhone;
	int workPhone;
	int mobilPhone;
	const char* additionally;

public:

	Abonent(char* fio, int homePhone, int workPhone, int mobilPhone, char* additionally)
	{
		this->fio = fio;
		this->homePhone = homePhone;
		this->workPhone = workPhone;
		this->mobilPhone = mobilPhone;
		this->additionally = additionally;
	}

	Abonent() : Abonent ("0", 0, 0, 0, "0")
	{
	}

	//Abonent(char* fio, int homePhone, int workPhone, int mobilPhone) : Abonent(fio, homePhone, workPhone, mobilPhone, '\0')
	//{
	//}

	//Abonent(char* fio, int homePhone, int workPhone) : Abonent (fio, homePhone, workPhone, 0, '\0')
	//{
	//}

	//Abonent(char* fio, int homePhone) : Abonent(fio, homePhone, 0, 0, '\0')
	//{
	//}



	void SetFio(const char* fio) { this->fio = fio; }
	const char* GetFio() { return fio; }

	void SetHomePhone(int homePhone) { this->homePhone = homePhone; }
	int GetHomePhone() { return homePhone; }

	void SetWorkPhone(int workPhone) { this->workPhone = workPhone; }
	int GetWorkPhone() { return workPhone; }

	void SetMobilPhone(int mobilPhone) { this->mobilPhone = mobilPhone; }
	int GetMobilPhone() { return mobilPhone; }

	void SetAdditionally(const char* additionally) { this->additionally = additionally; }
	const char* GetAdditionally() { return additionally; }

	~Abonent()
	{
		delete[] fio;
	}
};

class DatabaseAbonent
{
	vector <Abonent> databaseAbonent;

public:
	void AbonentBase(vector<Abonent>& databaseAbonent)
	{
		for (int i = 0; i < 3; i++)
		{
			Abonent abonent;
			abonent.SetFio("������� ������� �������");
			abonent.SetHomePhone(i);
			abonent.SetWorkPhone(i);
			abonent.SetMobilPhone(i);
			abonent.SetAdditionally("�����������");
			databaseAbonent.push_back(abonent);
		}
	}
	void ShowAbonentBase()
	{
		for (int i = 0; i < databaseAbonent.size(); i++)
		{
			cout << databaseAbonent.at(i).GetFio() << endl;
			cout << databaseAbonent.at(i).GetHomePhone() << endl;
			cout << databaseAbonent.at(i).GetWorkPhone() << endl;
			cout << databaseAbonent.at(i).GetMobilPhone() << endl;
			cout << databaseAbonent.at(i).GetAdditionally() << endl;
		}
	}
};

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	DatabaseAbonent StartDatabase;

	StartDatabase.ShowAbonentBase();

	system("pause");
}