#pragma once
#include <iostream>
#include "ArraySequence.h"
#include "Sequence.h"
template <typename T> 
class Vector {
private:
    MutableArraySequence<T>* data;
    void swap(Vector<T>& toSwap){
        MySwap( data,toSwap.data);
    }
public:
    Vector(int count)
    {
        if(count<1){
            std::invalid_argument("invalid size of vector");
        }
        this->data = new MutableArraySequence<T>(count);
    }
    Vector(T *items, int count)
    {
        this->data = new MutableArraySequence<T>(items, count);
    }

    Vector(const Sequence<T> &seq)
    {
        this->data = new MutableArraySequence<T>(seq);
    }

    Vector(const Vector<T> &vec)
    {
        this->data = new MutableArraySequence<T>(vec.Size());
        for (int i = 0; i < vec.Size(); i++)
        {
            this->data->Set(vec.Get(i), i);
        }
    }

    T Get(int index) const
    {
        return this->data->Get(index);
    }

    void Set(T item ,int index) 
    {
        this->data->Set(item,index);
    }
    int Size() const
    {
        return this->data->GetLength();
    }

    Vector<T>* Sum(const Vector<T> &vec)
    {
        
        if (this->Size() != vec.Size())
        {
            throw std::invalid_argument("incompatible size");
        }
        Vector<T>* result  = new Vector<T>(Size());
        for (int i = 0; i < this->Size(); i++)
        {
            result->Set( this->Get(i) + vec.Get(i) , i);
        }
    
        return result ;
    }

    Vector<T>* Mult( T item )
    {
        Vector<T>* result  = new Vector<T>(Size());
        for (int i = 0; i < this->Size(); i++)
        {
            result->Set( this->Get(i) * item , i);
        }
        return result;
    }

    T scalarProd(const Vector<T> &vec2)
    {
        if (this->Size() != vec2.Size())
        {
            throw std::invalid_argument("incompatible size");
        }
        T result = this->Get(0)*vec2.Get(0);
        for (int i = 1; i < this->Size(); i++)
        {
            result+=(this->Get(i)*vec2.Get(i));
        }
        return result;
    }

   

    Vector<T>& operator+(Vector<T> &vec)
    {
        Vector<T>* result = this->Sum(vec);
        return *result;
    }
    Vector<T>& operator+=(Vector<T> &vec)
    {
        (*this) = (*this) + vec;
        return (*this);
    }
    T operator*(Vector<T> &vec)
    {
        return this->scalarProd(vec);
    }
    Vector<T>& operator*(T item)
    {
        Vector<T>* result = this->Mult(item);
        return (*result);
    }
    Vector<T>& operator*=(T item)
    {
       (*this) = (*this) * T;
        return (*this);
    }

    T operator[](int index)
    {
        return (*this)[index];
    }
    
    Vector operator=(Vector<T>& vec)
    {
        Vector<T> result (vec);
        swap(result);
        return *this;
    } 
    virtual ~Vector()
    {
        delete data;
    }
};

template <typename T> 
void PrintVector(Vector<T> &vec)
{
    for (int i = 0; i < vec.Size(); i++)
    {
        std::cout << vec.Get(i) << " ";
    }
    std::cout << std::endl;
}