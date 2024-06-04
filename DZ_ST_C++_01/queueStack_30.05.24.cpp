#include <iostream>
#include <algorithm>
#include <span>
#include <string>
#include <functional>

using namespace std;

// Стэк

//class Node
//{
//public:
//
//	int value;
//	Node* next;
//
//	Node() : Node(0, nullptr)
//	{
//	}
//	
//	Node(const int value, Node* next)
//	{
//		this->value = value;
//		this->next = next;
//	}
//
//};
//
//class Stack
//{
//	Node* head;
//
//public:
//
//	Stack()
//	{
//		head = nullptr;
//	}
//
//	Stack(const int value)
//	{
//		Node* newNode = new Node(value, nullptr);
//		head = newNode;
//	}
//
//	~Stack()
//	{
//		while(head!=nullptr)
//		{
//			Node* forDelete = head;
//			head = head->next;
//			delete forDelete;
//		}
//	}
//
//	bool IsEmpty()const
//	{
//		return head == nullptr;
//	}
//
//	void Push(int value)
//	{
//		if (IsEmpty())
//		{
//			head = new Node(value, nullptr);
//		}
//		else
//		{
//			Node* newNode = new Node(value, head);
//		}
//
//	}
//
//	int Pop()
//	{
//		
//		if (IsEmpty())
//			return 0;
//
//		int result = head->value;
//		
//		Node* forDelete = head;
//
//		head = head->next;
//		delete forDelete;
//
//		return result;
//	}
//
//	void ForEach(const function<void(int)>action)const
//	{
//
//	}
//};
//void main()
//{
//	Stack stack;
//	stack.Push(1);
//	stack.Push(2);
//	stack.Push(3);
//
//	cout << stack.Pop() << endl;// 3
//	cout << stack.Pop() << endl;// 2
//	cout << stack.Pop() << endl;// 1
//
//	system("pause");
//}


//// Стэк на основе очереди (queue)

//class Node
//{
//public:
//
//	int value;
//	Node* next;
//
//	Node() : Node(0, nullptr)
//	{
//	}
//
//	Node(const int value, Node* next)
//	{
//		this->value = value;
//		this->next = next;
//	}
//
//};
//
//class Stack
//{
//	Node* head;
//	Node* tail;
//
//public:
//
//	Stack()
//	{
//		head = nullptr;
//		tail = nullptr;
//	}
//
//	Stack(const int value)
//	{
//		Node* newNode = new Node(value, nullptr);
//		head = tail = newNode;
//	}
//
//	~Stack()
//	{
//		while (head != tail)
//		{
//			Node* forDelete = head;
//			head = head->next;
//			delete forDelete;
//		}
//	}
//
//	bool IsEmpty()const
//	{
//		return head == nullptr;
//	}
//
//	void Push(int value)
//	{
//		if (IsEmpty())
//		{
//			head = tail = new Node(value, nullptr);
//		}
//		else
//		{
//			Node* newNode = new Node(value, nullptr);
//			tail = tail->next = newNode;
//		}
//
//	}
//
//	int Pop()
//	{
//
//		if (IsEmpty())
//			return 0;
//
//		int result = head->value;
//
//		Node* forDelete = head;
//
//		head = head->next;
//		delete forDelete;
//
//		if (head == nullptr)
//			tail = nullptr;
//
//		return result;
//	}
//
//	void ForEach(const function<void(int)>action)const
//	{
//
//	}
//};
//
//
//void main()
//{
//	Stack stack;
//	stack.Push(1);
//	stack.Push(2);
//	stack.Push(3);
//	stack.Push(4);
//	stack.Push(5);
//	stack.Push(6);
//
//	cout << stack.Pop() << endl;
//	cout << stack.Pop() << endl;
//	cout << stack.Pop() << endl;
//	cout << stack.Pop() << endl;
//	cout << stack.Pop() << endl;
//	cout << stack.Pop() << endl;
//
//	system("pause");
//}


// Стэк со вложенным классом + очередь со вложенным классом
 
//template<typename TValue>
//class Stack
//{
//    struct StackNode
//    {
//        TValue Value;
//        StackNode* Next;
//
//    StackNode(const TValue& value, StackNode* next)
//    {
//        Value = value;
//        Next = next;
//    }
//    };
//
//    StackNode* head;
//
//public:
//    Stack()
//    {
//        head = nullptr;
//    }
//
//    ~Stack()
//    {
//        Clear();
//    }
//
//    bool IsEmpty() const
//    {
//        return head == nullptr;
//    }
//
//    void Clear()
//    {
//        while (head != nullptr)
//        {
//            const StackNode* forDelete = head;
//            head = head->Next;
//            delete forDelete;
//        }
//    }
//
//    void Push(const TValue value)
//    {
//        if (IsEmpty())
//            head = new StackNode(value, nullptr);
//        else
//            head = new StackNode( value, head );
//    }
//
//    TValue Pop()
//    {
//        if (IsEmpty())
//            return 0;
//
//        const TValue result = head->Value;
//        const StackNode* forDelete = head;
//
//        head = head->Next;
//
//        delete forDelete;
//        return result;
//    }
//
//    void ForEach(const function<void(TValue)> action) const
//    {
//        StackNode* current = head;
//        while (current != nullptr)
//        {
//            action(current->Value);
//            current = current->Next;
//        }
//
//        //for (StackNode* current = head; current != nullptr; current = current->Next)
//        //  action(current->Value);
//    }
//};
//
//template<typename TValue>
//class Queue
//{
//    struct QueueNode
//    {
//        TValue Value;
//        QueueNode* Next;
//
//    QueueNode(const TValue& value, QueueNode* next)
//    {
//        Value = value;
//        Next = next;
//    }
//    };
//
//    QueueNode* head;
//    QueueNode* tail;
//
//public:
//    Queue()
//    {
//        head = tail = nullptr;
//    }
//
//    ~Queue()
//    {
//        Clear();
//    }
//
//    bool IsEmpty() const
//    {
//        return head == nullptr;
//    }
//
//    void Clear()
//    {
//        while (head != nullptr)
//        {
//            const QueueNode* forDelete = head;
//            head = head->Next;
//            delete forDelete;
//        }
//
//        tail = nullptr;
//    }
//
//    void Push(const TValue& value)
//    {
//        if (IsEmpty())
//            head = tail = new QueueNode(value, nullptr);
//        else
//            tail = tail->Next = new QueueNode(value, nullptr);
//    }
//
//    TValue Pop()
//    {
//        if (IsEmpty())
//            return 0;
//
//        const TValue result = head->Value;
//        const QueueNode* forDelete = head;
//
//        head = head->Next;
//        if (head == nullptr)
//            tail = nullptr;
//
//        delete forDelete;
//        return result;
//    }
//
//    void ForEach(const function<void(TValue)> action) const
//    {
//        QueueNode* current = head;
//        while (current != nullptr)
//        {
//            action(current->Value);
//            current = current->Next;
//        }
//    }
//};
//
//class Point
//{
//	int x, y;
//
//public:
//	Point() : Point(0, 0)
//	{
//	}
//
//    Point(const int value) :Point (value, value)
//    {
//    }
//
//	Point(const int x, const int y)
//	{
//		this->x = x;
//		this->y = y;
//	}
//
//	int GetX() const { return x; }
//	void SetX(int x) { this->x = x; }
//
//	int GetY() const { return y; }
//	void SetY(int y) { this->y = y; }
//};
//
//string to_string(const Point& point)
//{
//	return "(" + to_string(point.GetX()) + "," + to_string(point.GetY()) + ")";
//}
//
//
//void WorkWithStack()
//{
//    Stack<int> stack;
//
//    stack.Push(1);
//    stack.Push(2);
//    stack.Push(3);
//
//    //cout << stack.Pop() << endl; // 3
//    //cout << stack.Pop() << endl; // 2
//    //cout << stack.Pop() << endl; // 1
//
//    stack.ForEach([](int value) { cout << value << " "; });
//    cout << endl;
//
//    Stack<double> stack2;
//
//    stack2.Push(45.5);
//    stack2.Push(46.6);
//    stack2.Push(55.8);
//
//    //cout << stack2.Pop() << endl; // 3
//    //cout << stack2.Pop() << endl; // 2
//    //cout << stack2.Pop() << endl; // 1
//
//    stack2.ForEach([](double value) { cout << value << " "; });
//    cout << endl;
//
//}
//
//void WorkWithQueue()
//{
//    Queue<int> queue;
//
//    queue.Push(1);
//    queue.Push(2);
//    queue.Push(3);
//
//    cout << queue.Pop() << endl; // 1
//    cout << queue.Pop() << endl; // 2
//    cout << queue.Pop() << endl; // 3
//
//    //queue.ForEach([](int value) {cout << value << " "; });
//    cout << endl;
//}
//
//void WorkWithPointQueue()
//{
//    Queue<Point> queue;
//
//    queue.Push(Point(1, 2));
//    queue.Push(Point(6, 5));
//    queue.Push(Point(7, 1));
//
//    //cout << to_string(queue.Pop()) << endl; // 1
//    //cout << to_string(queue.Pop()) << endl; // 2
//    //cout << to_string(queue.Pop()) << endl; // 3
//
//    queue.ForEach([](Point value) {cout << to_string(value) << " "; });
//    cout << endl;
//
//}
//
//
//// Стэк на основе массива
//
//template<typename TValue>
//class ArrayStack
//{
//    int size;
//    int index;
//    TValue* arr;
//
//public:
//
//    ArrayStack(int size)
//    {
//        this->size = size;
//        index = 0;
//        arr = new TValue[size];
//    }
//
//    ~ArrayStack()
//    {
//        delete[] arr;
//    }
//
//    bool IsEmpty()
//    {
//        return index == 0;
//    }
//
//    bool IsFull()
//    {
//        return index == size;
//    }
//
//    void Clear()
//    {
//        index = 0;
//    }
//
//    void Push(const TValue& value)
//    {
//        if (IsFull())
//            return;
//        else
//        {
//            arr[index] = value;
//            index++;
//        }
//
//    }
//
//    TValue Pop()
//    {
//        if (IsEmpty())
//            return 0;
//        index--;
//        TValue result = arr[index];
//        return result;
//    }
//
//    void ForEach()
//    {
//    }
//};
//
//void WorkWithArrayStack()
//{
//    ArrayStack<int> stack(3);
//
//    cout << "Stack is empty / is full: " << stack.IsEmpty() << " " << stack.IsFull() << endl;
//
//    stack.Push(1);
//    stack.Push(2);
//    stack.Push(3);
//
//    cout << "Stack is empty / is full: " << stack.IsEmpty() << " " << stack.IsFull() << endl;
//
//    cout << stack.Pop() << endl; // 3
//
//    cout << "Stack is empty / is full: " << stack.IsEmpty() << " " << stack.IsFull() << endl;
//
//    cout << stack.Pop() << endl; // 2
//
//    cout << "Stack is empty / is full: " << stack.IsEmpty() << " " << stack.IsFull() << endl;
//
//    cout << stack.Pop() << endl; // 1
//
//    cout << "Stack is empty / is full: " << stack.IsEmpty() << " " << stack.IsFull() << endl;
//
//}
//
//void main()
//{
//    //WorkWithStack();
//    //WorkWithQueue();
//    //WorkWithPointQueue();
//    WorkWithArrayStack();
//
//    system("pause");
//}

// Наследование классов

//Задача №1

//class Passport
//{
//	int serialNumber;
//	int number;
//public:
//
//	Passport():Passport(0, 0)
//	{
//
//	}
//
//	Passport(int serial, int number)
//	{
//		this->serialNumber = serial;
//		this->number = number;
//	}
//
//	void SetSerialNumber(int serialNumber) { this->serialNumber = serialNumber; }
//	int GetSerialNumber() { return serialNumber; }
//	void SetNumber(int number) { this->number = number; }
//	int GetNumber() { return number; }
//
//};
//
//class ForeignPassport :public Passport
//{
//	int foreignNumber;
//
//public:
//
//	ForeignPassport() :ForeignPassport(0,0,0)
//	{
//
//	}
//
//	ForeignPassport(int foreignNumber, int serialNumber, int number):Passport(serialNumber, number)
//	{
//		this->foreignNumber = foreignNumber;
//		
//	}
//
//	void SetForeignNumber(int serialNumber) { this->foreignNumber = foreignNumber; }
//	int GetForeignNumber() { return foreignNumber; }
//};
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	ForeignPassport pass1(1234, 12, 34);
//
//	cout << pass1.GetForeignNumber() << endl;
//	cout << pass1.GetSerialNumber() << endl;
//	cout << pass1.GetNumber() << endl;
//
//	pass1.SetForeignNumber(987654);
//	pass1.SetNumber(654);
//	pass1.SetSerialNumber(987);
//
//	cout << pass1.GetForeignNumber() << endl;
//	cout << pass1.GetSerialNumber() << endl;
//	cout << pass1.GetNumber() << endl;
//
//	system("pause");
//
//}

//Задача №2

//Задача - окружность вписанная в квадрат

//class Circle
//{
//	int radius;
//
//public:
//
//	Circle(int radius)
//	{
//		this->radius = radius;
//	}
//
//	void SetRadius(int radius) { this->radius = radius; }
//	int GetRadius() { return radius; }
//
//};
//
//class Square
//{
//	int length;
//
//public:
//
//	Square(int length)
//	{
//		this->length = length;
//	}
//
//	void SetLength(int length) { this->length = length; }
//	int GetLength() { return length; }
//
//};
//
//class CircleInSquare :public Square, public Circle
//{
//
//public:
//
//	CircleInSquare(int radius, int length):Square(length), Circle(radius)
//	{
//
//	}
//};
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	CircleInSquare cis(10, 15);
//
//	cout << cis.GetRadius() << endl;
//	cout << cis.GetLength() << endl;
//
//
//	system("pause");
//
//}


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
		length = other.length;
		str = other.str;

		other.str = nullptr;
		other.length = 0;

		return *this;
	}

};

class Array
{
	int size;
	int* arr;

	static void FixSize(int& size)
	{
		if (size < 0)
			size = 0;
	}

	static int GetRandomValue(int startRange, int endRange)
	{
		return rand() % (endRange - startRange + 1) + startRange;
	}

public:
	Array()
	{
		size = 0;
		arr = nullptr;
	}

	explicit Array(int size) : Array(size, 0)
	{
	}

	Array(int size, int value)
	{
		FixSize(size);

		this->size = size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = value;
	}

	Array(int* arr, int size)
	{
		FixSize(size);

		this->size = size;
		this->arr = new int[size];
		for (int i = 0; i < size; i++)
			this->arr[i] = arr[i];
	}

	Array(const Array& other)
	{
		size = other.size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = other.arr[i];
	}

	Array(Array&& other)
	{
		size = other.size;
		arr = other.arr;

		other.size = 0;
		other.arr = nullptr;
	}

	~Array()
	{
		if (arr != nullptr)
			delete[] arr;
	}

	int Size() const
	{
		return size;
	}

	int& At(const int index)
	{
		return arr[index];
	}

	int At(const int index) const
	{
		return arr[index];
	}

	bool IsEmpty() const
	{
		return size == 0;
	}

	void Clear()
	{
		size = 0;

		if (arr != nullptr)
			delete[] arr;

		arr = nullptr;
	}

	void Resize(int size)
	{
		FixSize(size);

		int* newArr = size == 0 ? nullptr : new int[size];
		int minSize = min(this->size, size);
		for (int i = 0; i < minSize; i++)
			newArr[i] = arr[i];
		for (int i = minSize; i < size; i++)
			newArr[i] = 0;

		if (arr != nullptr)
			delete[] arr;

		this->size = size;
		arr = newArr;
	}

	void Randomize(int startRange, int endRange)
	{
		if (IsEmpty())
			return;

		for (int i = 0; i < size; i++)
			arr[i] = GetRandomValue(startRange, endRange);
	}

	void Sort(bool desc = false)
	{
		if (IsEmpty())
			return;

		if (desc)
			sort(arr, arr + size, [](int& a, int& b) { return a > b; });
		else
			sort(arr, arr + size, [](int& a, int& b) { return a < b; });
	}

	void Swap(int firstIndex, int secondIndex)
	{
		swap(arr[firstIndex], arr[secondIndex]);
	}

	void Concatenate(const Array& other)
	{
		if (other.IsEmpty())
			return;

		int newSize = size + other.size;
		int* newArr = new int[newSize];
		for (int i = 0; i < size; i++)
			newArr[i] = arr[i];
		for (int i = 0; i < other.size; i++)
			newArr[size + i] = other.arr[i];

		if (arr != nullptr)
			delete[] arr;

		this->size = newSize;
		arr = newArr;
	}

	void Insert(int index, int value)
	{
		int newSize = size + 1;
		int* newArr = new int[newSize];
		for (int i = 0; i < index; i++)
			newArr[i] = arr[i];
		newArr[index] = value;
		for (int i = index; i < size; i++)
			newArr[i + 1] = arr[i];

		if (arr != nullptr)
			delete[] arr;

		this->size = newSize;
		arr = newArr;
	}

	void InsertFront(int value)
	{
		Insert(0, value);
	}

	void InsertBack(int value)
	{
		Insert(size, value);
	}

	void Remove(int index)
	{
		if (size <= 1)
		{
			Clear();
			return;
		}

		int newSize = size - 1;
		int* newArr = new int[newSize];
		for (int i = 0; i < index; i++)
			newArr[i] = arr[i];
		for (int i = index; i < newSize; i++)
			newArr[i] = arr[i + 1];

		if (arr != nullptr)
			delete[] arr;

		this->size = newSize;
		arr = newArr;
	}

	void RemoveFront()
	{
		Remove(0);
	}

	void RemoveBack()
	{
		Remove(size - 1);
	}

	void Replace(int oldValue, int newValue)
	{
		for (int i = 0; i < size; i++)
			if (arr[i] == oldValue)
				arr[i] = newValue;
	}

	double GetAverage() const
	{
		if (IsEmpty())
			return 0;

		int sum = 0;
		for (int x : span(arr, arr + size))
			sum += x;

		return (double)sum / size;
	}

	int GetSum() const
	{
		int sum = 0;
		for (int x : span(arr, arr + size))
			sum += x;

		return sum;
	}

	int GetMin() const
	{
		if (IsEmpty())
			return 0;

		int min = arr[0];
		for (int x : span(arr, arr + size))
			if (x < min)
				min = x;

		return min;
	}

	int GetMax() const
	{
		if (IsEmpty())
			return 0;

		int max = arr[0];
		for (int x : span(arr, arr + size))
			if (x > max)
				max = x;

		return max;
	}

	int Find(int value) const
	{
		for (int i = 0; i < size; i++)
			if (arr[i] == value)
				return i;

		return -1;
	}

	int FindLast(int value) const
	{
		for (int i = size - 1; i >= 0; i--)
			if (arr[i] == value)
				return i;

		return -1;
	}

	string ToString() const
	{
		return ToString(", ");
	}

	string ToString(string separator) const
	{
		if (IsEmpty())
			return "";

		string str = to_string(arr[0]);
		for (int x : span(arr + 1, arr + size))
			str += separator + to_string(x);

		return str;
	}
};

void F1(Array arr)
{
	cout << "arr = [" << arr.ToString() << "] with size = " << arr.Size() << endl;
}

void main()
{
	setlocale(LC_ALL, "ru");

	MyString str1;
	MyString str2 = "Qwerty";
	MyString str3 = "Hello, World!";
	MyString str4 = str2;
	MyString str5 = str2 + str3;

	cout << "str1 = " << str1.GetStr() << endl;
	cout << "str2 = " << str2.GetStr() << endl;
	cout << "str3 = " << str3.GetStr() << endl;
	cout << "str4 = " << str4.GetStr() << endl;
	cout << "str5 = " << str5.GetStr() << endl;


	Array arr2(4);
	Array arr3(5, 777);
	Array arr4(arr3);
	Array arr1 = arr2;


	cout << "arr1 = [" << arr1.ToString() << "] with size = " << arr1.Size() << endl;
	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;
	cout << "arr3 = [" << arr3.ToString() << "] with size = " << arr3.Size() << endl;
	cout << "arr4 = [" << arr4.ToString() << "] with size = " << arr4.Size() << endl;



	system("pause");
}
