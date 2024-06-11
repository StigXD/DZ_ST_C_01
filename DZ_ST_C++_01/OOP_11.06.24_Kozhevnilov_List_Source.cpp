#include <iostream>
#include <algorithm>
#include <span>
#include <string>
#include <functional>
#include <vector>

using namespace std;

template <class TValue>
class List
{
public:
    virtual ~List() = default;

    virtual int GetSize() const = 0;
    virtual bool IsEmpty() const = 0;

    virtual TValue GetFront() const = 0;
    virtual TValue GetBack() const = 0;
    virtual void Add(const int index, const TValue& value) = 0;
    virtual void AddToFront(const TValue& value) = 0;
    virtual void AddToBack(const TValue& value) = 0;
    virtual void Remove(const int index) = 0;
    virtual void RemoveFromFront() = 0;
    virtual void RemoveFromBack() = 0;

    virtual void Clear() = 0;

    virtual TValue operator[](const int index) const = 0;
    virtual TValue& operator[](const int index) = 0;
};

template <class TValue>
class ArrayList : public List<TValue>
{
    // реализаци€ списка на основе динамического массива

    int size;
    TValue* arr;

public:

    ArrayList():ArrayList(0, 0)
    {

    }

    ArrayList(const TValue value, const int size)
    {
        this->size = size;
        arr = new TValue[size];
        for (int i = 0; i < size; i++)
            arr[i] = value;
    }

    ArrayList(const ArrayList <TValue>& other)
    {
        this->size = other.size;
        arr = new TValue[size];
        for (int i = 0; i < size; i++)
            arr[i] = other.arr[i];
    }

    ArrayList(ArrayList <TValue>&& other)
    {
    }


    ~ArrayList()
    {
        if (arr != nullptr)
            delete[]arr;
    }

    int GetSize() const override
    {
        return size;
    }

    bool IsEmpty() const override
    {
        return size == 0;
    }

    TValue GetFront() const override
    {
        if (IsEmpty())
            return 0;
        return arr[0];
    }

    TValue GetBack() const override
    {
        if (IsEmpty())
            return 0;
        return arr[size - 1];
    }

    void Add(const int index, const TValue& value) override
    {
        TValue* newArr = new TValue[size+1];
        for (int i = 0; i < index; i++)
            newArr[i] = arr[i];

        for (int i = index; i < size; i++)
            newArr[i+1] = arr[i];

        newArr[index] = value;

        this->size += 1;

        delete[] arr;
        arr = newArr;
    }

    void AddToFront(const TValue& value) override
    {
        Add(0, value);
    }

    void AddToBack(const TValue& value)override
    {
        Add(size-1, value);
    }

    void Remove(const int index) override
    {
        TValue* newArr = new TValue[size - 1];
        for (int i = 0; i < index; i++)
            newArr[i] = arr[i];

        for (int i = index; i < size-1; i++)
            newArr[i] = arr[i+1];

        this->size -= 1;

        delete[] arr;
        arr = newArr;
    }

    void RemoveFromFront() override
    {
        Remove(0);
    }

    void RemoveFromBack() override
    {
        Remove(size - 1);
    }

    void Clear() override
    {
        if (IsEmpty())
            return;

        this->size = 0;

        delete[] arr;
        arr = nullptr;
    }

    TValue operator[](const int index) const override
    {
        return arr[index];
    }
    TValue& operator[](const int index) override
    {
        return arr[index];
    }

};

template <class TValue>
class DoublyLinkedList : public List<TValue>
{
    // реализаци€ списка на основе двусв€зного списка
};

template <class TValue>
class LinkedList : public List<TValue>
{
    // реализаци€ списка на основе односв€зного списка

    struct StackNode
    {
        TValue Value;
        StackNode* Next;
        
        StackNode(const TValue& value, StackNode* next)
        {
            Value = value;
            Next = next;
        }
    };
        
            StackNode* head;
            public:
    Stack()
    {
        head = nullptr;
    }

    ~Stack()
    {
        Clear();
    }

    bool IsEmpty() const
    {
        return head == nullptr;
    }

    void Clear()
    {
        while (head != nullptr)
        {
            const StackNode* forDelete = head;
            head = head->Next;
            delete forDelete;
        }
    }

    void Push(const TValue value)
    {
        if (IsEmpty())
            head = new StackNode(value, nullptr);
        else
            head = new StackNode( value, head );
    }

    TValue Pop()
    {
        if (IsEmpty())
            return 0;

        const TValue result = head->Value;
        const StackNode* forDelete = head;

        head = head->Next;

        delete forDelete;
        return result;
    }

    void ForEach(const function<void(TValue)> action) const
    {
        StackNode* current = head;
        while (current != nullptr)
        {
            action(current->Value);
            current = current->Next;
        }

        //for (StackNode* current = head; current != nullptr; current = current->Next)
        //  action(current->Value);
    }

};

template <class TValue>
class VectorList : public List<TValue>
{
    // реализаци€ списка на основе вектора

    vector <TValue> list;

public:
    
    VectorList()
    {
        
    }

    VectorList(const TValue value)
    {
        list.push_back(value);
    }

    VectorList(const TValue value, const int size)
    {
        for (int i = 0; i < size; i++)
            list.push_back(value);
    }

    VectorList(const vector <TValue>& other)
    {
        for (int i = 0; i < other.size(); i++)
            list.push_back(other[i]);
    }


    int GetSize() const override
    {
        return list.size();
    }

    bool IsEmpty() const override
    {
        return list.empty();
    }

    TValue GetFront() const override
    {
        return list.front();
    }

    TValue GetBack() const override
    {
        return list.back();
    }

    void Add(const int index, const TValue& value) override
    {
        list.insert(list.begin()+index, value);
    }

    void AddToFront(const TValue& value) override
    {
        list.insert(list.begin(), value);
    }

    void AddToBack(const TValue& value)override
    {
        list.push_back(value);
    }

    void Remove(const int index) override
    {
        list.erase(list.begin() + index);
    }

    void RemoveFromFront() override
    {
        list.erase(list.begin());
    }

    void RemoveFromBack() override
    {
        list.pop_back();
    }

    void Clear() override
    {
        list.clear();
    }

    TValue operator[](const int index) const override
    {
        return list.at(index);
    }
    TValue& operator[](const int index) override
    {
        return list.at(index);
    }

};

template <template <typename> class TList, typename TValue>
class StackQueue
{
protected:
    TList<TValue>* list;

    StackQueue()
    {
        list = new TList<TValue>();
    }

    StackQueue(const StackQueue<TList, TValue>& other)
    {
        list = new TList<TValue>(*other.list);
    }

    StackQueue(StackQueue<TList, TValue>&& other)
    {
        list = other.list;
        other.list = nullptr;
    }

    virtual ~StackQueue()
    {
        if (list != nullptr)
            delete list;
    }

public:
    bool IsEmpty()
    {
        return list->IsEmpty();
    }

    virtual void Push(const TValue& value) = 0;

    virtual TValue Pop() = 0;

    virtual TValue Peek() = 0;

    void Clear()
    {
        // todo
    }

    StackQueue& operator=(const StackQueue<TList, TValue>& other)
    {
        // todo
    }

    StackQueue& operator=(StackQueue<TList, TValue>&& other)
    {
        // todo
    }
};

template <template <typename> class TList, typename TValue>
class Queue : StackQueue<TList, TValue>
{
public:
    Queue() : StackQueue<TList, TValue>()
    {
    }

    Queue(const Queue& other) : StackQueue<TList, TValue>(other)
    {
    }

    Queue(Queue&& other) : StackQueue<TList, TValue>(other)
    {
    }

    ~Queue() override
    {
    }

    void Push(const TValue& value) override
    {
        this->list->AddToBack(value);
    }

    TValue Pop() override
    {
        // todo
    }

    TValue Peek() override
    {
        // todo
    }

    Queue& operator=(const Queue<TList, TValue>& other)
    {
        // todo
    }

    Queue& operator=(Queue<TList, TValue>&& other)
    {
        // todo
    }
};

template <template <typename> class TList, typename TValue>
class Stack : StackQueue<TList, TValue>
{
    // todo
};

class Point
{
    int x, y;

public:
    Point() : Point(0, 0)
    {
    }

    Point(const int value) : Point(value, value)
    {
    }

    Point(const int x, const int y)
    {
        this->x = x;
        this->y = y;
    }

    int GetX() const { return x; }
    void SetX(const int x) { this->x = x; }

    int GetY() const { return y; }
    void SetY(const int y) { this->y = y; }
};

ostream& operator<<(ostream& out, const Point& point)
{
    out << "(" << point.GetX() << ", " << point.GetY() << ")";
    return out;
}



void SimpleTests()
{
    //Stack<LinkedList, int> stack;

    //stack.Push(1);
    //stack.Push(2);
    //stack.Push(3);

    //cout << endl << "Expected 3 of stack.Peek, received: " << stack.Peek() << endl;
    //cout << "Expected 3 of stack.Pop, received: " << stack.Pop() << endl;

    //cout << endl << "Expected 2 of stack.Peek, received: " << stack.Peek() << endl;
    //cout << "Expected 2 of stack.Pop, received: " << stack.Pop() << endl;

    //Queue<LinkedList, int> queue;

    //queue.Push(1);
    //queue.Push(2);
    //queue.Push(3);

    //cout << endl << "Expected 1 of queue.Peek, received: " << queue.Peek() << endl;
    //cout << "Expected 1 of queue.Pop, received: " << queue.Pop() << endl;

    //cout << endl << "Expected 2 of queue.Peek, received: " << queue.Peek() << endl;
    //cout << "Expected 2 of queue.Pop, received: " << queue.Pop() << endl;
}



template <template <typename> class TList, typename TValue>
void ListTests()
{
    TList<TValue> list;

    list.AddToFront(2);
    list.AddToFront(1);
    list.AddToBack(4);
    list.Add(2, 3);

    cout << endl;
    cout << "Items expecting: ";
    for (int i = 1; i <= 4; i++)
        cout << (TValue)i << " ";
    cout << endl;

    cout << "Items received:  ";
    for (int i = 0; i < list.GetSize(); i++)
        cout << list[i] << " ";
    cout << endl;

    list.RemoveFromFront();
    list.RemoveFromFront();
    list.RemoveFromBack();

    cout << "Items expecting: " << (TValue)3 << endl;

    cout << "Items received:  ";
    for (int i = 0; i < list.GetSize(); i++)
        cout << list[i] << " ";
    cout << endl;

    cout << list.GetSize() << endl;
    cout << list.IsEmpty() << endl;
    cout << list.GetFront() << endl;
    cout << list.GetBack() << endl;
    list.Clear();
    cout << list.IsEmpty() << endl;

}

void main()
{
    setlocale(LC_ALL, "ru");

    ListTests <VectorList, int>();
    ListTests <ArrayList, int>();

    system("pause");
}