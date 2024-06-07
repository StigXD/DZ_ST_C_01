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


// Полиморфизм
// Виртуальные функции

//class Pet
//{
//	string name;
//
//public:
//	
//	Pet()
//	{
//		this->name = "Empty";
//	}
//	
//	Pet(const string& name)
//	{
//		this->name = name;
//	}
//
//	virtual void SoundPet()
//	{
//		cout << "None" << endl;
//	}
//
//	virtual void PrintNamePet()
//	{
//		cout << name << endl;
//	}
//	
//	virtual void PrintPet()
//	{
//		cout << "Тип животного => Pet" << endl;
//	}
//
//};
//
//class Dog : public Pet
//{
//	string name;
//
//public:
//
//	Dog()
//	{
//		this->name = "Empty";
//	}
//
//	Dog(const string& name): Pet(name)
//	{
//	}
//
//	void SoundPet()override
//	{
//		cout << "Gav" << endl;
//	}
//
//	void PrintPet()override
//	{
//		cout << "Тип животного => Dog" << endl;
//	}
//
//};
//
//class Cat : public Pet
//{
//	string name;
//
//public:
//
//	Cat() 
//	{
//		this->name = "Empty";
//	}
//
//	Cat(const string& name) : Pet(name)
//	{
//	}
//
//	void SoundPet()override
//	{
//		cout << "Mew" << endl;
//	}
//
//	void PrintPet()override
//	{
//		cout << "Тип животного => Cat" << endl;
//	}
//
//};
//
//class Parrot : public Pet
//{
//	string name;
//
//public:
//
//	Parrot()
//	{
//		this->name = "Empty";
//	}
//
//	Parrot(const string& name) : Pet(name)
//	{
//	}
//
//
//	void SoundPet()override
//	{
//		cout << "Popka durak" << endl;
//	}
//
//	void PrintPet()override
//	{
//		cout << "Тип животного => Parrot" << endl;
//	}
//
//};
//
//class Hamster : public Pet
//{
//	string name;
//
//public:
//
//	Hamster() 
//	{
//		this->name = "Empty";
//	}
//
//	Hamster(const string& name) : Pet(name)
//	{
//	}
//
//
//
//	void SoundPet() override
//	{
//		cout << "Pipipi" << endl;
//	}
//
//	void PrintPet()override
//	{
//		cout << "Тип животного => Hamster" << endl;
//	}
//
//};
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	vector<Pet*> pet;
//	pet.push_back(new Dog("Cobaka"));
//	pet.push_back(new Cat("Koshka"));
//	pet.push_back(new Parrot("Popygay"));
//	pet.push_back(new Hamster("Homyak"));
//
//	for (int i = 0; i < pet.size(); i++)
//	{
//		pet[i]->PrintPet();
//		pet[i]->PrintNamePet();
//		pet[i]->SoundPet();
//	}
//
//	system("pause");
//}

// Задание №1
//Создать базовый класс "список". Реализовать на базе списка стек и очередь с виртууальными функциями вставки и вытаскивания

//class List
//{
//protected:
//	struct ListNode
//	{
//		int Value;
//	    ListNode* Next;
//	
//	    ListNode(const int& value, ListNode* next)
//	    {
//	        Value = value;
//	        Next = next;
//	    }
//	};
//	
//	    ListNode* head;
//	    ListNode* tail;
//	
//	public:
//		List()
//	    {
//	        head = tail = nullptr;
//	    }
//	
//	    ~List()
//	    {
//	        Clear();
//	    }
//	
//	    bool IsEmpty() const
//	    {
//	        return head == nullptr;
//	    }
//	
//	    void Clear()
//	    {
//	        while (head != nullptr)
//	        {
//	            const ListNode* forDelete = head;
//	            head = head->Next;
//	            delete forDelete;
//	        }
//	
//	        tail = nullptr;
//	    }
//	
//	    virtual void Push(const int& value)
//	    {
//	        if (IsEmpty())
//	            head = tail = new ListNode(value, nullptr);
//	        else
//	            tail = tail->Next = new ListNode(value, nullptr);
//	    }
//	
//	    virtual int Pop()
//	    {
//	        if (IsEmpty())
//	            return 0;
//	
//	        const int result = head->Value;
//	        const ListNode* forDelete = head;
//	
//	        head = head->Next;
//	        if (head == nullptr)
//	            tail = nullptr;
//	
//	        delete forDelete;
//	        return result;
//	    }
//	
//	    void ForEach(const function<void(int)> action) const
//	    {
//	        ListNode* current = head;
//	        while (current != nullptr)
//	        {
//	            action(current->Value);
//	            current = current->Next;
//	        }
//	    }
//
//};
//
//class Queue:public List
//{
//
//	Queue()
//	{
//		head = tail = nullptr;
//	}
//
//	~Queue()
//	{
//		Clear();
//	}
//
//};
//
//class Stack
//{
//
//};
//
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


//Задача №3 - Создать абстрактный класс Транспортное средство и производные классы автомобиль, велосипед, повозка.
//посчитать время и стоимость перевозки людей и грузов

//class Transport
//{
//public:
//
//	virtual double Time() = 0;
//	virtual double Cost() = 0;
//};
//
//class Car: public Transport
//{
//	double distance;
//	int velocity = 100;
//	int expense = 10;
//	double weight;
//
//public:
//
//	Car():Car(0,0)
//	{
//
//	}
//
//	Car(double distance, double weight)
//	{
//		this->distance = distance;
//		this->weight = weight;
//
//	}
//
//	double Time() override
//	{
//		double time;
//		return time = distance / velocity;
//	}
//
//	double Cost() override
//	{
//		double cost;
//		return cost = (distance * expense)/weight;
//	}
//};
//
//class Bike:public Transport
//{
//	double distance;
//	int velocity = 15;
//	int expense = 1;
//	int tonnage = 10;
//	double weight;
//
//public:
//
//	Bike() :Bike(0,0)
//	{
//
//	}
//
//	Bike(double distance, double weight)
//	{
//		this->distance = distance;
//		this->weight = weight;
//	}
//
//	double Time() override
//	{
//		double time;
//		return time = distance / velocity;
//	}
//
//	double Cost() override
//	{
//		double cost;
//		return cost = (distance * expense) / weight;
//	}
//
//};
//
//class Carriage:public Transport
//{
//	double distance;
//	int velocity = 20;
//	int expense = 5;
//	int tonnage = 5000;
//	double weight;
//
//public:
//
//	Carriage() :Carriage(0,0)
//	{
//
//	}
//
//	Carriage(double distance, double weight)
//	{
//		this->distance = distance;
//		this->weight = weight;
//	}
//	
//	double Time() override
//	{
//		double time;
//		return time = distance / velocity;
//	}
//
//	double Cost() override
//	{
//		double cost;
//		return cost = (distance * expense) / weight;
//	}
//
//};
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	Car car1(1000, 100);
//	Bike bike1(50, 10);
//	Carriage carriage1(150, 2000);
//
//	cout << car1.Cost() << endl;
//	cout << car1.Time() << endl << endl;
//
//	cout << bike1.Cost() << endl;
//	cout << bike1.Time() << endl << endl;
//
//	cout << carriage1.Cost() << endl;
//	cout << carriage1.Time() << endl << endl;
//
//
//	system("pause");
//}

//Задача №4 - Создать абстрактный класс Employer с чисто виртуальной функцией Print. Создать три класса President, Manager, Worker.
//переопределить функцию Print

//class Employer
//{
//protected:
//	string name;
//
//public:
//
//	Employer(string& name)
//	{
//		this->name = name;
//	}
//
//	virtual void Print() = 0;
//
//};
//
//class President : public Employer
//{
//	
//	string yearsInPost;
//
//public:
//
//	President(string& name, string& yearsInPost) :Employer(name)
//	{
//		this->yearsInPost = yearsInPost;
//	}
//
//	void Print() override
//	{
//		cout << "Имя директора => " << name << endl;
//		cout << "Лет в должности => " << yearsInPost << endl;
//	}
//
//};
//
//class Manager : public Employer
//{
//	string post;
//
//public:
//
//	Manager(string& name, string& post) :Employer(name)
//	{
//		this->post = post;
//	}
//
//	void Print() override
//	{
//		cout << "Имя менеджера => " << name << endl;
//		cout << "Должности => " << post << endl;
//	}
//
//
//};
//
//class Worker : public Employer
//{
//	string specialization;
//
//public:
//
//
//	Worker(string& name, string& specialization) :Employer(name)
//	{
//		this->specialization = specialization;
//	}
//
//	void Print() override
//	{
//		cout << "Имя рабочего => " << name << endl;
//		cout << "Профессия => " << specialization << endl;
//	}
//
//
//};
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	vector<Employer*> employer;
//	employer.push_back(new President("President", "10"));
//
//	system("pause");
//}

//Задача №5 - Создать абстрактный базовый класс с виртуальной функцией - площадь. Создать произвольные классы прямоугольник круг, прмоуголный треугольник, трапеция со своими функциями площади.
// Для проверки определить массив ссылок на абстрактный объектный класс, которым присваиваются адреса различных объектов.

class Square
{
public:

	virtual double CalculatingSquare() = 0;

};

class Rectangle: public Square
{
	int a;
	int b;
public:

	Rectangle(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	double CalculatingSquare() override
	{
		double square = (double)a*b;
		return square;
	}

};

class Circle : public Square
{
	int radius;
	double pi = 3.14;
public:

	Circle(int radius)
	{
		this->radius = radius;
	}

	double CalculatingSquare() override
	{
		double square = pow(pi*radius,2);
		return square;
	}

};

class Triangle : public Square
{
	int a;
	int b;
public:

	Triangle(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	double CalculatingSquare() override
	{
		double square = (double)a * b / 2;
		return square;
	}

};

class Trapezoid : public Square
{
	int a;
	int b;
	int h;
public:

	Trapezoid(int a, int b, int h)
	{
		this->a = a;
		this->b = b;
		this->h = h;
	}

	double CalculatingSquare() override
	{
		double square = ((double)a + b) / 2*h;
		return square;
	}

};

void main()
{
	setlocale(LC_ALL, "ru");

	vector<Square*> square;
	square.push_back(new Rectangle(2,3));
	square.push_back(new Circle(3));
	square.push_back(new Triangle(2, 3));
	square.push_back(new Trapezoid(2, 3, 2));

	for (int i = 0; i < square.size(); i++)
		cout << square[i]->CalculatingSquare() << endl;


	system("pause");

}