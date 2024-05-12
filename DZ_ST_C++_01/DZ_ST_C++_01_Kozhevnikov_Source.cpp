#include <iostream>
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
	string fio;
	int homePhone;
	int workPhone;
	int mobilPhone;
	string additionally;

public:

	Abonent() : Abonent(0, 0, 0, 0, 0)
	{

	}

	Abonent(string fio, int homePhone, int workPhone, int mobilPhone, string additionally)
	{
		Abonent::fio = fio;
		Abonent::homePhone = homePhone;
		Abonent::workPhone = workPhone;
		Abonent::mobilPhone = mobilPhone;
		Abonent::additionally = additionally;
	}

	void SetFio(string fio) { Abonent::fio = fio; }
	string GetFio() { return fio; }

	void SetHomePhone(int homePhone) { Abonent::homePhone = homePhone; }
	int GetHomePhone() { return homePhone; }

	void SetWorkPhone(int workPhone) { Abonent::workPhone = workPhone; }
	int GetWorkPhone() { return workPhone; }

	void SetMobilPhone(int mobilPhone) { Abonent::mobilPhone = mobilPhone; }
	int GetMobilPhone() { return mobilPhone; }

	void SetAdditionally(string additionally) { Abonent::additionally = additionally; }
	string GetAdditionally() { return additionally; }
};