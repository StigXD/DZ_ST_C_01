#pragma once
#include <iostream>
#include <algorithm>
#include <span>
#include <string>
#include <functional>
#include <vector>

using namespace std;

template <class TValue>
class VectorList : public List<TValue>
{
    // реализация списка на основе вектора

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
        list.insert(list.begin() + index, value);
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

