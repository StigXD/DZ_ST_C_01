#include <iostream>
#include <algorithm>
#include <span>
#include <string>

using namespace std;

//class Point
//{
//	double x;
//	double y;
//	double z;
//
//public:
//
//	Point() : Point (0, 0, 0)
//	{
//
//	}
//
//	Point(double x, double y, double z)
//	{
//		Point::x = x;
//		Point::y = y;
//		Point::z = z;
//	}
//
//	double GetX()
//	{
//		return x;
//	}
//	void SetX(double value)
//	{
//		x = value;
//	}
//	double GetY()
//	{
//		return y;
//	}
//	void SetY(double value)
//	{
//		y = value;
//	}
//	double GetZ()
//	{
//		return z;
//	}
//	void SetZ(double value)
//	{
//		z = value;
//	}
//};
//
//void main()
//{
//	Point point (456,46,4);
//	//point.SetX(1);
//	//point.SetY(2);
//	//point.SetZ(3);
//
//	cout << point.GetX() << endl;
//	cout << point.GetY() << endl;
//	cout << point.GetZ() << endl;
//
//	system("pause");
//}

// Класс Массив 14.05.2024

//class Array
//{
//	int size;
//	int* arr;
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
//		this->size = size;
//		arr = new int[size];
//		for (int i = 0; i < size; i++)
//			arr[i] = value;
//	}
//
//	Array(int* arr, int size) 
//	{
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
//	~Array() 
//	{
//		delete[] arr;
//	}
//
//	int Size() const
//	{
//		return size;
//	}
//
//	bool IsEmpty() const
//	{
//		return size == 0;
//	}
//
//	 void Clear()
//	 {
//		 if (arr!=nullptr)
//			 delete[] arr;
//
//		 arr = nullptr;
//		 size = 0;
//	 }
//
//	int& At(int index)
//	{
//		return arr[index];
//	}
//
//	int At(int index) const
//	{
//		return arr[index];
//	}
//
//	void Resize(int size)
//	{
//		if (size < 0)
//			size = 0;
//
//		int* tempArr = size == 0 ? nullptr : new int[size];
//		int minSize = min(this->size, size);
//		for (int i = 0; i < minSize; i++)
//			tempArr[i] = arr[i];
//		for (int i = minSize; i < size; i++)
//			tempArr[i] = 0;
//		
//		if (arr!=nullptr)
//			delete[] arr;
//		
//		arr = tempArr;
//		this->size = size;
//	}
//
//	void Randomize(int startRange, int endRange)
//	{
//		for (int i = 0; i < size; i++)
//			arr[i] = rand() % (endRange - startRange + 1) + startRange;
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
//	 void Swap(int firstIndex, int secondIndex)
//	 {
//		 swap(arr[firstIndex], arr[secondIndex]);
//	 }
//
//	 void Concatinate(const Array& other)
//	 {
//		 if (other.IsEmpty())
//			 return;
//		 int* tempArr = new int[size + other.size];
//		 for (int i = 0; i < size; i++)
//			 tempArr[i] = arr[i];
//		 for (int i = size; i < size + other.size; i++)
//			 tempArr[i] = other.arr[i-size];
//
//		 if (arr != nullptr)
//			 delete[] arr;
//
//		 arr = tempArr;
//		 size += other.size;
//
//	 }
//
//	 void Insert(int index, int value)
//	 {
//		 if (index > size || index < 0)
//			 return;
//
//		 int newSize = size + 1;
//		 int* tempArr = new int[newSize];
//		 for (int i = 0; i < index; i++)
//			 tempArr[i] = arr[i];
//		 for (int i = index+1; i < newSize; i++)
//			 tempArr[i] = arr[i - 1];
//		 tempArr[index] = value;
//
//		 if(arr!=nullptr)
//			delete[] arr;
//
//		 arr = tempArr;
//		 size = newSize;
//	 }
//
//	 void InsertFront(int value)
//	 {
//		 Insert(0, value);
//	 }
//
//	 void InsertBack(int value)
//	 {
//		 Insert(size-1, value);
//	 }
//
//	 void Remove(int index)
//	 {
//		 if (index > size-1 || index < 0)
//			 return;
//
//		 if (size - 1 < 0)
//			 Clear();
//
//		 int newSize = size - 1;
//		 int* tempArr = new int[newSize];
//		 for (int i = 0; i < index; i++)
//			 tempArr[i] = arr[i];
//		 for (int i = index; i < newSize; i++)
//			 tempArr[i] = arr[i + 1];
//
//		 if(arr!=nullptr)
//			delete[] arr;
//
//		 arr = tempArr;
//		 size = newSize;
//	 }
//
//	 void RemoveFront()
//	 {
//		 if (size - 1 < 0)
//			Clear();
//
//		 size -= 1;
//		 int* tempArr = new int[size];
//		 for (int i = 0; i < size; i++)
//			 tempArr[i] = arr[i+1];
//
//		 if (arr != nullptr)
//			 delete[] arr;
//
//		 arr = tempArr;
//	 }
//
//	 void RemoveBack()
//	 {
//		 if (size - 1 < 0)
//			 Clear();
//
//		 size -= 1;
//		 int* tempArr = new int[size];
//		 for (int i = 0; i < size; i++)
//			 tempArr[i] = arr[i];
//
//		 if (arr != nullptr)
//			 delete[] arr;
//		 arr = tempArr;
//	 }
//
//	 void Replace(int oldValue, int newValue)
//	 {
//		 for (int i : span(arr, arr + size))
//			 if (arr[i] = oldValue)
//				 arr[i] = newValue;
//	 }
//
//	double GetAverage() const
//	{
//		if (IsEmpty())
//			return 0;
//
//		double summ=0;
//		for (int i : span(arr, arr + size))
//			summ += arr[i];
//		return summ / size;
//	}
//
//	 int GetSum() const 
//	 {
//		 int sum = 0;
//		 for (int i : span(arr, arr + size))
//			 sum += arr[i];
//	 }
//
//
//	int GetMin() const
//	{
//		if (IsEmpty())
//			return 0;
//
//		int min = arr[0];
//		for (int i : span(arr, arr + size))
//			if (min > arr[i])
//				min = arr[i];
//		return min;
//	}
//
//	int GetMax() const
//	{
//		if (IsEmpty())
//			return 0;
//
//		int max = 0;
//		for (int i : span(arr, arr + size))
//			if (arr[i] > max)
//				max = arr[i];
//		return max;
//	}
//
//	 int Find(int value) // return index or -1
//	 {
//		 for (int i : span(arr, arr + size))
//			 if (arr[i] = value)
//				 return i;
//			 else
//				 return -1;
//	 }
//	 int FindLast(int value) // return index or -1
//	 {
//		 int index = -1;
//		 for (int i : span(arr, arr + size))
//			 if (arr[i] = value)
//				 index = i;
//		 return index;
//	 }
//
//	 Array operator+(int value) const
//	 {
//		 Array temp(*this);
//		 temp.Resize(temp.Size() + value);
//
//		 return temp;
//	 }
//
//
//	 Array operator+(const Array& other) const
//	 {
//		 Array temp(*this);
//		 if (other.IsEmpty())
//			 return temp;
//
//		 temp.size = size + other.size;
//		 temp.arr = new int[temp.size];
//		for (int i = 0; i < size; i++)
//			temp.arr[i] = arr[i];
//		for (int i = size; i < size + other.size; i++)
//			temp.arr[i] = other.arr[i - size];
//
//		//if (arr != nullptr)
//		//	delete[] arr;
//
//		//arr = tempArr;
//		//size += other.size;
//
//		return temp;
//	 }
//
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
//		for (int i : span(arr+1, arr + size))
//			str += separator + to_string(i);
//
//		return str;
//	}
//
//};
//
//Array operator+(int value, const Array& other)
//{
//	return other + value;
//}
//
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//
//	int temp[] = { 1,2,3,4 };
//
//	Array arr1;
//	Array arr2(3);
//	Array arr3(3, 999);
//	Array arr4(temp, size(temp));
//	Array arr5 = arr4;
//
//	cout << "arr1 = [" << arr1.ToString() << "] with size = " << arr1.Size() << endl;
//	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;
//	cout << "arr3 = [" << arr3.ToString() << "] with size = " << arr3.Size() << endl;
//	cout << "arr4 = [" << arr4.ToString() << "] with size = " << arr4.Size() << endl;
//	cout << "arr5 = [" << arr5.ToString() << "] with size = " << arr5.Size() << endl;
//
//	cout << endl << "Set value test" << endl;
//
//	arr2.At(1) = 123;
//	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;
//
//	cout << endl << "Is empty test" << endl;
//
//	cout << "arr1 is empty = " << arr1.IsEmpty() << endl;
//	cout << "arr2 is empty = " << arr2.IsEmpty() << endl;
//	cout << "arr3 is empty = " << arr3.IsEmpty() << endl;
//
//	cout << endl << "Resize test" << endl;
//
//	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;
//	arr2.Resize(2);
//	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;
//	arr2.Resize(4);
//	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;
//
//	cout << endl << "Randomize test" << endl;
//
//	arr2.Randomize(0, 9);
//	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;
//
//	cout << endl << "Sort test" << endl;
//
//	arr2.Sort();
//	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;
//	arr2.Sort(true);
//	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;
//
//	cout << endl << "Other tests" << endl;
//
//	cout << "arr2 = [" << arr2.ToString() << "] GetAverage = " << arr2.GetAverage() << endl;
//	cout << "arr2 = [" << arr2.ToString() << "] GetMin = " << arr2.GetMin() << endl;
//	cout << "arr2 = [" << arr2.ToString() << "] GetMax = " << arr2.GetMax() << endl;
//
//	cout << "arr2 with other separator = " << arr2.ToString(" # ") << endl;
//
//	cout << endl << "Operator+ test" << endl;
//	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;
//	cout << "arr3 = [" << arr3.ToString() << "] with size = " << arr3.Size() << endl;
//
//	Array arr6 = arr2 + arr3;
//	cout << "arr6 = [" << arr6.ToString() << "] with size = " << arr6.Size() << endl;
//	Array arr7 = arr6 + 3;
//	cout << "arr7 = [" << arr7.ToString() << "] with size = " << arr7.Size() << endl;
//	Array arr8 = 3 + arr6;
//	cout << "arr8 = [" << arr8.ToString() << "] with size = " << arr8.Size() << endl;
//
//
//	system("pause");
//}

// Класс Point 14.05.2024



//class Point
//{
//	int x;
//	int y;
//
//public:
//	int GetX() const { return x; } 
//
//	int GetY() const { return y; }
//
//	void SetX(int value) { this->x = x; }
//	void SetY(int value) { this->y = y; }
//	
//	Point() :Point(0, 0)
//	{
//
//	}
//	
//	Point(const Point& other) : Point(other.x, other.y)
//	{
//
//	}
//
//	Point(int x, int y)
//	{
//		this->x = x;
//		this->y = y;
//	}
//
//	//+(Point, Point)
//	
//	Point operator+(Point other)
//	{
//		Point temp;
//		temp.x = x + other.x;
//		temp.y = y + other.y;
//		return temp;
//	}
//
//	//+(Point, int)
//	Point operator+(const int value) const
//	{
//		Point temp;
//		temp.x = x + value;
//		temp.y = y + value;
//		return temp;
//	}
//
//	//+(int, Point)
//	friend Point operator+(const int value, const Point& other)
//	{
//		return other + value;
//	}
//
//	//-
//	 	Point operator-(Point other)
//	{
//		Point temp;
//		temp.x = x - other.x;
//		temp.y = y - other.y;
//		return temp;
//	}
//
//	Point operator-(int value)
//	{
//		Point temp;
//		temp.x = x - value;
//		temp.y = y - value;
//		return temp;
//	}
//
//	friend Point operator-(int value, Point& other)
//	{
//		Point temp = other;
//		temp.x = value - temp.x;
//		temp.y = value - temp.y;
//		return temp;
//	}
//
//
//	//*
//	Point operator*(Point other)
//	{
//		Point temp;
//		temp.x = x * other.x;
//		temp.y = y * other.y;
//		return temp;
//	}
//
//	Point operator*(int value)
//	{
//		Point temp;
//		temp.x = x * value;
//		temp.y = y * value;
//		return temp;
//	}
//
//	friend Point operator*(int value, Point& other)
//	{
//		Point temp = other;
//		temp.x *= value;
//		temp.y *= value;
//		return temp;
//	}
//
//	// /
//	Point operator/(Point other)
//	{
//		Point temp;
//		temp.x = x / other.x;
//		temp.y = y / other.y;
//		return temp;
//	}
//
//	Point operator/(int value)
//	{
//		Point temp;
//		temp.x = x / value;
//		temp.y = y / value;
//		return temp;
//	}
//
//	friend Point operator/(int value, Point& other)
//	{
//		Point temp = other;
//		temp.x = value/temp.x;
//		temp.y = value/temp.y;
//		return temp;
//	}
//
//	Point operator++()
//	{
//		++x;
//		++y;
//		return *this;
//	}
//
//	Point operator++(int)
//	{
//		Point temp(x, y);
//		++(*this);
//		return temp;
//	}
//
//	Point operator--()
//	{
//		--x;
//		--y;
//		return *this;
//	}
//
//	Point operator--(int)
//	{
//		Point temp(x, y);
//		--(*this);
//		return temp;
//	}
//
//};
//
//ostream& operator<< (ostream& output, const Point& point)
//{
//	return output << "(" << point.GetX()<< ", " << point.GetY() << ")" << endl;
//}
//
//istream& operator>> (istream& input,  Point& point)
//{
//	int temp;
//	input >> temp;
//	point.SetX(temp);
//	input >> temp; 
//	point.SetY(temp);
//	return input;
//}
//
//void main()
//{
//	Point point1(1, 2);
//	Point point2(3, 4);
//	cout << point1;
//	cout << point2;
//
//	Point point3 = point1 + point2;
//	cout << point3;
//
//	Point point4 = point1 + 5;
//	cout << point4;
//
//	Point point5 = 6 + point2;
//	cout << point5;
//
//	point3 = point1 - point2;
//	cout << point3;
//
//	point4 = point1 - 5;
//	cout << point4;
//
//	 point5 = 6 - point2;
//	cout << point5;
//
//	 point3 = point1 * point2;
//	cout << point3;
//
//	 point4 = point1 * 5;
//	cout << point4;
//
//	 point5 = 6 * point2;
//	cout << point5;
//
//	 point3 = point1 / point2;
//	cout << point3;
//
//	 point4 = point1 / 5;
//	cout << point4;
//
//	 point5 = 6 / point2;
//	cout << point5;
//
//
//
//	system("Pause");
//}

// Класс DateTime 14.05.2024

class TimeSpan
{
	long long totalMilliseconds;
	const int millisecondsInDay = 86400000;
	const int millisecondsInHours = 3600000;
	const int millisecondsInMinutes = 60000;
	const int millisecondsInSeconds = 1000;

public:

	TimeSpan()
	{
		totalMilliseconds = 0;
	}

	TimeSpan(long long days, long long hours, long long minutes, long long seconds, long long milliseconds )
	{
		totalMilliseconds += day * millisecondsInDay + hours * millisecondsInHours + minutes * millisecondsInMinutes + seconds * millisecondsInSeconds;
	}


	unsigned char GetDay() const { return totalMilliseconds / millisecondsInDay; }

	unsigned char GetHours() const { return (totalMilliseconds % millisecondsInDay / millisecondsInHours); }

	int GetTotalHours() const { return totalMilliseconds / millisecondsInHours; }

	int GetMinutes() const { return totalMilliseconds % millisecondsInHours / millisecondsInMinutes; }

	int GetTotalMinutes() const { return totalMilliseconds / millisecondsInMinutes; }

	int GetSeconds() const { return totalMilliseconds % millisecondsInMinutes / millisecondsInSeconds; }

	int GetTotalSeconds() const { return totalMilliseconds / millisecondsInSeconds; }

	long long GetMillisrconds() const { return totalMilliseconds % millisecondsInSeconds; }

	long long GetTotalMilliseconds() const { return totalMilliseconds; }

	TimeSpan operator-(const TimeSpan& rigth) const
	{
		TimeSpan tempA = *this;
		TimeSpan tempB = rigth;
		tempA.totalMilliseconds -= tempB.totalMilliseconds;
		return tempA;
	}

	TimeSpan operator+(const TimeSpan& rigth) const
	{
		TimeSpan tempA = *this;
		TimeSpan tempB = rigth;
		tempA.totalMilliseconds += tempB.totalMilliseconds;
		return tempA;
	}

	TimeSpan AddDays(long long days)
	{
		totalMilliseconds += days * millisecondsInDay;
		return *this;
	}

	TimeSpan AddHours(long long hours)
	{
		totalMilliseconds += hours * millisecondsInHours;
		return *this;
	}

	TimeSpan AddMinutes(long long minutes)
	{
		totalMilliseconds += minutes * millisecondsInMinutes;
		return *this;
	}

	TimeSpan AddSeconds(long long seconds)
	{
		totalMilliseconds += seconds * millisecondsInSeconds;
		return *this;
	}

	TimeSpan AddMilliseconds(long long milliseconds)
	{
		totalMilliseconds += milliseconds;
		return *this;
	}

	string ToString()const
	{
		return ToString(" ", ":", ".");
	}

	string ToString(const string& daySeparator, const string& timeSeparator, const string& millisecondsSeparator)const
	{
		return to_string(GetDay()) + daySeparator + to_string(GetHours()) + timeSeparator + to_string(GetMinutes()) + timeSeparator + to_string(GetSeconds()) + millisecondsSeparator + to_string(GetMillisrconds());
	}
	string ToString(const string& dayHoursSeparator, const string& hoursMinutesSeparator, const string& minutesSecondsSeparator, const string& secondsMillisecondsSeparator) const
	{
		return to_string(GetDay()) + dayHoursSeparator + to_string(GetHours()) + hoursMinutesSeparator + to_string(GetMinutes()) + minutesSecondsSeparator + to_string(GetSeconds()) + secondsMillisecondsSeparator + to_string(GetMillisrconds());
	}
};

class DateTime
{
	static const 

	unsigned short year;
	unsigned char month;
	unsigned char day;
	unsigned char hours;
	unsigned char minutes;
	unsigned char seconds;
	unsigned short milliseconds;

public:

	DateTime():DateTime(0, 0, 0, 0, 0, 0, 0)
	{
	
	}

	DateTime(unsigned short year, char month, char day) : DateTime(year, month, day, 0, 0, 0, 0)
	{

	}

	DateTime(unsigned short year, char month, char day, char hours, char minutes, char seconds) : DateTime( year,  month,  day,  hours,  minutes,  seconds, 0)
	{

	}

	DateTime(
		const unsigned short year,
		const char month,
		const char day,
		const char hours,
		const char minutes,
		const char seconds,
		const unsigned short milliseconds)
	{
		this->year = year;
		this->month = month;
		this->day = day;
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
		this->milliseconds = milliseconds;
	}

	unsigned short GetYear() { return year; }

	void SetYear(int year) { this->year = year; }

	char GetMonth() { return year; }

	void SetMonth(int month) { this->month = month; }

	char GetDay() { return year; }

	void SetDay(int day) { this->day = day; }

	char GetHours() { return year; }

	void SetHours(int hours) { this->hours = hours; }

	char GetMinutes() { return year; }

	void SetMinutes(int minutes) { this->minutes = minutes; }

	char GetSeconds() { return year; }

	void SetSeconds(int seconds) { this->seconds = seconds; }

	unsigned short GetMillisrconds() { return year; }

	void SetMillisrconds(int milliseconds) { this->milliseconds = milliseconds; }


	DateTime operator+(const TimeSpan& rigth) const
	{
		DateTime left = *this;
		TimeSpan result;
		result.AddDays(GetDay())
	}
	friend DateTime operator+(const TimeSpan& left, const DateTime& rigth)
	{

	}
	DateTime operator-(const TimeSpan& rigth) const
	{

	}
	friend DateTime operator-(const DateTime& left, const TimeSpan& rigth)
	{

	}

	string ToString();
};

void main()
{
	setlocale(LC_ALL, "ru");

	TimeSpan data;

	data.AddDays(1);
	data.AddHours(1);
	data.AddMinutes(1);
	data.AddSeconds(1);
	data.AddMilliseconds(1);


	cout << data.ToString(" ", ":", ".") << endl;
	cout << data.GetTotalHours() << endl;
	cout << data.GetTotalMinutes() << endl;
	cout << data.GetTotalSeconds() << endl;
	cout << data.GetTotalMilliseconds() << endl;

	DateTime dt1(2024, 05, 25);
	DateTime dt2(2024, 05, 24);
	DateTime dt3(2024, 05, 24, 23, 59, 59);
	DateTime dt4(2024, 05, 24, 23, 59, 59, 999);
	DateTime dt5(2024, 05, 25, 0, 0, 1);
	DateTime dt6(2024, 05, 25, 0, 0, 0, 1);
	DateTime dt7(2024, 05, 24, 1, 1, 1, 1);
	DateTime dt8(2024, 05, 25, 1, 1, 1, 1);

	TimeSpan ts1(0, 0, 0, 1);
	TimeSpan ts2(0, 0, 0, -1);
	TimeSpan ts3(0, 0, 1, 0);
	TimeSpan ts4(0, 0, -1, 0);
	TimeSpan ts5(0, 1, 0, 0);
	TimeSpan ts6(0, -1, 0, 0);
	TimeSpan ts7(1, 0, 0, 0);
	TimeSpan ts8(-1, 0, 0, 0);
	TimeSpan ts9(100, 0, 0, 0);
	TimeSpan ts0(-100, 0, 0, 0);

	cout << endl << "DateTime - DateTime" << endl;
	cout << dt1.ToString() << " - " << dt1.ToString() << " = " << (dt1 - dt1).ToString() << endl;
	cout << dt1.ToString() << " - " << dt2.ToString() << " = " << (dt1 - dt2).ToString() << endl;
	cout << dt1.ToString() << " - " << dt3.ToString() << " = " << (dt1 - dt3).ToString() << endl;
	cout << dt1.ToString() << " - " << dt4.ToString() << " = " << (dt1 - dt4).ToString() << endl;
	cout << dt1.ToString() << " - " << dt5.ToString() << " = " << (dt1 - dt5).ToString() << endl;
	cout << dt1.ToString() << " - " << dt6.ToString() << " = " << (dt1 - dt6).ToString() << endl;
	cout << dt1.ToString() << " - " << dt7.ToString() << " = " << (dt1 - dt7).ToString() << endl;
	cout << dt1.ToString() << " - " << dt8.ToString() << " = " << (dt1 - dt8).ToString() << endl;

	cout << endl << "DateTime + TimeSpan" << endl;
	cout << dt1.ToString() << " + " << ts1.ToString() << " = " << (dt1 + ts1).ToString() << endl;
	cout << dt1.ToString() << " + " << ts2.ToString() << " = " << (dt1 + ts2).ToString() << endl;
	cout << dt1.ToString() << " + " << ts3.ToString() << " = " << (dt1 + ts3).ToString() << endl;
	cout << dt1.ToString() << " + " << ts4.ToString() << " = " << (dt1 + ts4).ToString() << endl;
	cout << dt1.ToString() << " + " << ts5.ToString() << " = " << (dt1 + ts5).ToString() << endl;
	cout << dt1.ToString() << " + " << ts6.ToString() << " = " << (dt1 + ts6).ToString() << endl;
	cout << dt1.ToString() << " + " << ts7.ToString() << " = " << (dt1 + ts7).ToString() << endl;
	cout << dt1.ToString() << " + " << ts8.ToString() << " = " << (dt1 + ts8).ToString() << endl;
	cout << dt1.ToString() << " + " << ts9.ToString() << " = " << (dt1 + ts9).ToString() << endl;
	cout << dt1.ToString() << " + " << ts0.ToString() << " = " << (dt1 + ts0).ToString() << endl;

	cout << endl << "DateTime - TimeSpan" << endl;
	cout << dt1.ToString() << " - " << ts1.ToString() << " = " << (dt1 - ts1).ToString() << endl;
	cout << dt1.ToString() << " - " << ts2.ToString() << " = " << (dt1 - ts2).ToString() << endl;
	cout << dt1.ToString() << " - " << ts3.ToString() << " = " << (dt1 - ts3).ToString() << endl;
	cout << dt1.ToString() << " - " << ts4.ToString() << " = " << (dt1 - ts4).ToString() << endl;
	cout << dt1.ToString() << " - " << ts5.ToString() << " = " << (dt1 - ts5).ToString() << endl;
	cout << dt1.ToString() << " - " << ts6.ToString() << " = " << (dt1 - ts6).ToString() << endl;
	cout << dt1.ToString() << " - " << ts7.ToString() << " = " << (dt1 - ts7).ToString() << endl;
	cout << dt1.ToString() << " - " << ts8.ToString() << " = " << (dt1 - ts8).ToString() << endl;
	cout << dt1.ToString() << " - " << ts9.ToString() << " = " << (dt1 - ts9).ToString() << endl;
	cout << dt1.ToString() << " - " << ts0.ToString() << " = " << (dt1 - ts0).ToString() << endl;
	
	cout << endl << "DateTime - TimeSpan + TimeSpan" << endl;
	cout << dt1.ToString() << " - " << ts1.ToString() << " + " << ts1.ToString() << " = " << (dt1 - ts1 + ts1).ToString() << endl;
	cout << dt1.ToString() << " - " << ts2.ToString() << " + " << ts2.ToString() << " = " << (dt1 - ts2 + ts2).ToString() << endl;
	cout << dt1.ToString() << " - " << ts3.ToString() << " + " << ts3.ToString() << " = " << (dt1 - ts3 + ts3).ToString() << endl;
	cout << dt1.ToString() << " - " << ts4.ToString() << " + " << ts4.ToString() << " = " << (dt1 - ts4 + ts4).ToString() << endl;
	cout << dt1.ToString() << " - " << ts5.ToString() << " + " << ts5.ToString() << " = " << (dt1 - ts5 + ts5).ToString() << endl;
	cout << dt1.ToString() << " - " << ts6.ToString() << " + " << ts6.ToString() << " = " << (dt1 - ts6 + ts6).ToString() << endl;
	cout << dt1.ToString() << " - " << ts7.ToString() << " + " << ts7.ToString() << " = " << (dt1 - ts7 + ts7).ToString() << endl;
	cout << dt1.ToString() << " - " << ts8.ToString() << " + " << ts8.ToString() << " = " << (dt1 - ts8 + ts8).ToString() << endl;
	cout << dt1.ToString() << " - " << ts9.ToString() << " + " << ts9.ToString() << " = " << (dt1 - ts9 + ts9).ToString() << endl;
	cout << dt1.ToString() << " - " << ts0.ToString() << " + " << ts0.ToString() << " = " << (dt1 - ts0 + ts0).ToString() << endl;

	system("pause");

}