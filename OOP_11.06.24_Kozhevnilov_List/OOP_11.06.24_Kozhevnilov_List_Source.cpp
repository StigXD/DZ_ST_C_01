#include <iostream>
#include <algorithm>
#include <span>
#include <string>
#include <functional>
#include <vector>

using namespace std;


#include "List.h"
#include "ArrayList.h"
#include "VectorList.h"
//#include "LinkedList.h"
//#include"DoubleLinkedList.h"




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