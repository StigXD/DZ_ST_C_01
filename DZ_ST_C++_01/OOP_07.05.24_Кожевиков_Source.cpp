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

public:
	int GetDay() { return totalMilliseconds / 86400000; }

	int GetHours() { return (totalMilliseconds / 3600000 % 60); }

	int GetTotalHours() { return totalMilliseconds / 3600000; }

	int GetMinutes() { return totalMilliseconds / 60000 % 60; }

	int GetTotalMinutes() { return totalMilliseconds / 60000; }

	int GetSeconds() { return totalMilliseconds / 1000 % 60; }

	int GetTotalSeconds() { return totalMilliseconds / 1000; }

	long long GetMillisrconds() { return totalMilliseconds % 1000; }

	long long GetTotalMillisrconds() { return totalMilliseconds; }

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
		totalMilliseconds += days * 86400000;
		return *this;
	}

	TimeSpan AddHours(long long hours)
	{
		totalMilliseconds += hours * 3600000;
		return *this;
	}

	TimeSpan AddMinutes(long long minutes)
	{
		totalMilliseconds += minutes * 60000;
		return *this;
	}

	TimeSpan AddSeconds(long long seconds)
	{
		totalMilliseconds += seconds * 1000;
		return *this;
	}

	TimeSpan AddMillisrconds(long long milliseconds)
	{
		totalMilliseconds += milliseconds;
		return *this;
	}

	string ToString()
	{

	}

	string ToString(string& daySeparator, string& timeSeparator, string& millisecondsSeparator)
	{

	}
	string ToString(string& dayHoursSeparator, string& hoursMinutesSeparator, string& minutesSecondsSeparator, string& secondsMillisecondsSeparator)
	{
		return (GetDay() + dayHoursSeparator + GetHours() + hoursMinutesSeparator + GetMinutes() + minutesSecondsSeparator + GetSeconds() + secondsMillisecondsSeparator + GetMillisrconds());
	}
};

//class DateTime
//{
//	unsigned short year;
//	unsigned char month;
//	unsigned char day;
//	unsigned char hours;
//	unsigned char minutes;
//	unsigned char seconds;
//	unsigned short milliseconds;
//
//public:
//
//	DateTime() {}
//
//	DateTime(int year, int month, int day, int hours, int minutes, int seconds) {}
//
//	DateTime(int year, int month, int day, int hours, int minutes, int seconds,int milliseconds) {}
//
//	int GetYear();
//	void SetYear(int year);
//	int GetMonth();
//	void SetMonth(int month);
//	int GetDay();
//	void SetDay(int day);
//	int GetHours();
//	void SetHours(int hours);
//	int GetMinutes();
//	void SetMinutes(int minutes);
//	int GetSeconds();
//	void SetSeconds(int seconds);
//	int GetMillisrconds();
//	void SetMillisrconds(int milliseconds);
//
//	DateTime operator+(const TimeSpan& rigth) const;
//	friend DateTime operator+(const TimeSpan& left, const DateTime& rigth);
//
//	TimeSpan operator-(const DateTime& rigth) const;
//	DateTime operator-(const TimeSpan& rigth) const;
//	friend DateTime operator-(const TimeSpan& left, const DateTime& rigth);
//
//	string ToString();
//};

void main()
{
	setlocale(LC_ALL, "ru");

	TimeSpan data;

	data.AddDays(1);



	system("pause");

}