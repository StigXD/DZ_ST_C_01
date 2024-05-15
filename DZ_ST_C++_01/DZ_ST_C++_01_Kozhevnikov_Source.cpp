#include <iostream>
#include <vector>
#include <Windows.h>
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
			abonent.SetFio("Абонент Абонент Абонент");
			abonent.SetHomePhone(i);
			abonent.SetWorkPhone(i);
			abonent.SetMobilPhone(i);
			abonent.SetAdditionally("Отсутствует");
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