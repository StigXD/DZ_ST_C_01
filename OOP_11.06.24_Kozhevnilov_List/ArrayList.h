#pragma once
#include <iostream>
#include <algorithm>
#include <span>
#include <string>
#include <functional>
#include <vector>

using namespace std;

template <class TValue>
class ArrayList : public List<TValue>
{
    // реализация списка на основе динамического массива

    int size;
    TValue* arr;

public:

    ArrayList() :ArrayList(0, 0)
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
        TValue* newArr = new TValue[size + 1];
        for (int i = 0; i < index; i++)
            newArr[i] = arr[i];

        for (int i = index; i < size; i++)
            newArr[i + 1] = arr[i];

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
        Add(size - 1, value);
    }

    void Remove(const int index) override
    {
        TValue* newArr = new TValue[size - 1];
        for (int i = 0; i < index; i++)
            newArr[i] = arr[i];

        for (int i = index; i < size - 1; i++)
            newArr[i] = arr[i + 1];

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
