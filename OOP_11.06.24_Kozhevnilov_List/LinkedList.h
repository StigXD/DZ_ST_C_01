#pragma once
#include <iostream>
#include <algorithm>
#include <span>
#include <string>
#include <functional>
#include <vector>

using namespace std;



template <class TValue>
class LinkedList : public List<TValue>
{
    // реализация списка на основе односвязного списка

protected:
	struct ListNode
	{
		int Value;
	    ListNode* Next;
	
	    ListNode(const int& value, ListNode* next)
	    {
	        Value = value;
	        Next = next;
	    }
	};
    int size;
    ListNode* head;
    ListNode* tail;

public:
    LinkedList()
    {
        head = nullptr;
    }

    ~LinkedList()
    {
        Clear();
    }

    int GetSize() const override
    {
        return size;
    }


    bool IsEmpty() const
    {
        return head == nullptr;
    }

    void Clear()
    {
        while (head != nullptr)
        {
            const ListNode* forDelete = head;
            head = head->Next;
            delete forDelete;
        }
    }

    TValue GetFront() const override
    {
        while (head->Next != nullptr)
        {
            head = head->Next;
        }
        return head->Value;
    }

    TValue GetBack() const override
    {
        return head->Value;
    }

    void Add(const int index, const TValue& value) override
    {
        size++;
        for (int i = 0; i<index; i++)
            head = head->Next;
        ListNode* newNode = this->head;
        newNode = new ListNode(value, newNode->Next->Next);

    }

    void AddToFront(const TValue& value) override
    {
        while (head->Next != nullptr)
        {
            head = head->Next;
        }
        head->Next = new ListNode(value, nullptr);
        size++;
    }

    void AddToBack(const TValue& value)override
    {
        if (IsEmpty())
        {
           head = new ListNode(value, nullptr);
           size++;
        }

        else
        {
           head = new ListNode(value, head);
           size++;
        }

    }

    void Remove(const int index) override
    {
        if (size <= 1)
        {
            Clear();
            return;
        }

    }

    void RemoveFromFront() override
    {
        if (IsEmpty())
            return 0;

        const TValue result = head->Value;
        const ListNode* forDelete = head;

        head = head->Next;

        delete forDelete;
        return result;

    }

    void RemoveFromBack() override
    {
        if (IsEmpty())
            return 0;

        while (head->Next->Next != nullptr)
        {
            head = head->Next;
        }
        const TValue result = head->Value;
        const ListNode* forDelete = head;

        head = head->Next;

        delete forDelete;
        return result;

    }

    //void ForEach(const function<void(TValue)> action) const
    //{
    //    StackNode* current = head;
    //    while (current != nullptr)
    //    {
    //        action(current->Value);
    //        current = current->Next;
    //    }

        //for (StackNode* current = head; current != nullptr; current = current->Next)
        //  action(current->Value);
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
