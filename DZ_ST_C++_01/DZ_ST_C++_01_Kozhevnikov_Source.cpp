#include <iostream>
#include <vector>
#include <Windows.h>
#include <stdio.h>
#include <span>
using namespace std;

//Задание №1. Реализуйте класс Дробь.Необходимо хранить числитель и знаменатель в качестве переменных - членов. Реализуйте функции - члены для ввода данных
//в переменные - члены, для выполнения арифметических операций (сложение, вычитание, умножение, деление, и т.д.).

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
//	cout << "Дробь 1:" << endl;
//	cout << "Введите числитель" << endl;
//	cin >> numerator;
//	fract1.SetNumerator(numerator);
//	cout << "Введите знаменатель" << endl;
//	cin >> denominator;
//	fract1.SetDenominator(denominator);
//
//	cout << "Дробь 2:" << endl;
//	cout << "Введите числитель" << endl;
//	cin >> numerator;
//	fract2.SetNumerator(numerator);
//	cout << "Введите знаменатель" << endl;
//	cin >> denominator;
//	fract2.SetDenominator(denominator);
//
//	resultFract.Addition(fract1, fract2, resultFract);
//	cout << "Сумма = " << resultFract.GetNumerator() << "/" << resultFract.GetDenominator() << endl;
//
//	resultFract.Difference(fract1, fract2, resultFract);
//	cout << "Разность = " << resultFract.GetNumerator() << "/" << resultFract.GetDenominator() << endl;
//
//	resultFract.Multiplication(fract1, fract2, resultFract);
//	cout << "Произведение = " << resultFract.GetNumerator() << "/" << resultFract.GetDenominator() << endl;
//
//	resultFract.Degree(fract1, fract2, resultFract);
//	cout << "Деление = " << resultFract.GetNumerator() << "/" << resultFract.GetDenominator() << endl;
//
//	system("pause");
//}

//Задание №2. Создайте приложение "Телефонная книга". Необходимо хранить данные об абоненте (ФИО, домашний телефон, рабочий телефон, мобильный телефон,
//дополнительная информация о контакте) внутри соответствующего класса. Наполните класс переменными - членами, функциями - членами, конструкторами,
//inline - функциями - членами, используйте инициализаторы, реализуйте деструктор.
//Обязательно необходимо выделять динамически память под ФИО. Предоставьте пользователю возможность добавлять новых абонентов, удалять абонентов,
//искать абонентов по ФИО, показывать всех абонентов, сохранять информацию в файл и загружать из файла.

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
			int size = strlen(other.fio)+1;
			this->fio = new char[size];
			strcpy_s(this->fio, size, other.fio);
		}
		else
			this->fio = nullptr;

		if (other.additionally != nullptr)
		{
			int size = strlen(other.additionally)+1;
			this->additionally = new char[size];
			strcpy_s(this->additionally, size, other.additionally);
		}
		else
			this->additionally = nullptr;

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

	void SetFio (char* fio)
	{
		int size = strlen(fio) + 1;
		this-> fio = new char[size];
		strcpy_s(this->fio, size, fio);
	}

	const char* GetFio() { return fio; }

	void SetHomePhone(long long homePhone)	{this->homePhone = homePhone;}
	long long GetHomePhone() { return homePhone; }

	void SetWorkPhone(long long workPhone)	{this->workPhone = workPhone;}
	long long GetWorkPhone() { return workPhone; }

	void SetMobilPhone(long long mobilPhone)  {this->mobilPhone = mobilPhone;}
	long long GetMobilPhone() { return mobilPhone; }

	void SetAdditionally(char* additionally)
	{
		int size = strlen(additionally) + 1;
		this ->additionally = new char[size];
		strcpy_s(this->additionally, size, additionally);
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
		cout << "Введите ФИО абонента" << endl;
		cin.ignore();
		abonent.SetFio(gets_s(fio, size));

		cout << "Введите домашний номер" << endl;
		long long homePhone;
		cin >> homePhone;
		abonent.SetHomePhone(homePhone);

		cout << "Введите рабочий номер" << endl;
		long long workPhone;
		cin >> workPhone;
		abonent.SetWorkPhone(workPhone);

		cout << "Введите мобильный номер" << endl;
		long long mobilPhone;
		cin >> mobilPhone;
		abonent.SetMobilPhone(mobilPhone);

		char additionally[size];
		cout << "Введите доп. информацию" << endl;
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
			cout << "Абонент " << i + 1 << endl;
			cout << "ФИО: " << abonentBase.at(i).GetFio() << endl;
			cout << "Домашний номер: " << abonentBase.at(i).GetHomePhone() << endl;
			cout << "Рабочий номер: " << abonentBase.at(i).GetWorkPhone() << endl;
			cout << "Мобильный номер: " << abonentBase.at(i).GetMobilPhone() << endl;
			cout << "Доп. информация: " << abonentBase.at(i).GetAdditionally() << endl << endl;
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
		cout << "МЕНЮ" << endl << endl << endl;
		cout << "Выберите действие: " << endl;
		cout << "1 - Показать базу абонентов" << endl;
		cout << "2 - Добавить абонента" << endl;
		cout << "3 - Найти информацию об абоненте" << endl;
		cout << "4 - Удалить абонента" << endl;
		cout << "5 - Копировать запись абонента" << endl;
		cout << "0 - Выход" << endl;

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
					cout << "Абонент " << i + 1 << endl;
					cout << "Нет данных" << endl;
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
			cout << "Введите имя абонента" << endl;
			const int size = 128;
			char abonentName[size];
			cin.ignore();
			int resultFind = abonentBase.FindAbonent(gets_s(abonentName, size));
			if (resultFind == -1)
				cout << "Совпадений нет!" << endl;
			else
				abonentBase.ShowAbonentBase(resultFind);
			break;
		}
		case 4:
		{
			cout << "Введите номер абонента для удаления" << endl;
			int deleteNumber;
			cin >> deleteNumber;
			int deleteResult = abonentBase.DeleteAbonent(deleteNumber-1);
			if (deleteResult == -1)
				cout << "Ошибка операции. Неверный номер абонента." << endl;
			break;
		}
		case 5:
		{
			cout << "Введите номер абонента для копирования" << endl;
			int copyNumber;
			cin >> copyNumber;
			int copyResult = abonentBase.CopyAbonent(copyNumber - 1);
			if (copyResult == -1)
				cout << "Ошибка операции. Неверный номер абонента." << endl;
			break;
		}

		}
		system("pause");
		system("cls");
	}
	system("pause");
}