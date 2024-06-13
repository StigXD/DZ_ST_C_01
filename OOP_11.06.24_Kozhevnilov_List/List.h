#pragma once
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
