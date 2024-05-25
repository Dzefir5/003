#pragma once
#include <iostream>
#include "Sequence.h"
#include "ListSequence.h"
#include "MySwap.h"

template <typename T> 
class Stack
{
private:
    MutableListSequence<T> *data;
    void swap(Stack<T>& toSwap){
        MySwap( data,toSwap.data);
    }
public:
    Stack()
    {
        data = new MutableListSequence<T>();
    }

    Stack(T *array, int count)
    {
        data = new MutableListSequence<T>(array, count);
    }

    Stack(const Sequence<T> &seq)
    {
        data = new MutableListSequence<T>(seq);
    }

    Stack(const Stack<T> &stack)
    {
        data = new MutableListSequence<T>();
        for (int i = 0; i < stack.data->GetLength(); i++)
        {
           data->Append(stack.data->Get(i));
        }
    }

    void push(const T &item)
    {
        this->data->Append(item);
    }

    T peek()
    {   
        if(data->GetLength()!=0){
            return data->GetLast();
        }
        else{
            throw std::out_of_range("");
        }
    }
    T pop()
    {   
        if(data->GetLength()>0){
            T result = data->GetLast();
            data->RemoveAt(data->GetLength()-1 );
            return result;
        }
        else{
            throw std::out_of_range("");
        }
    }

    int size()
    {
        return  data->GetLength();
    }

    void empty()
    {
        return data->GetLength() == 0 ;
    }

    Stack<T> *Concat(Stack<T> &stack)
    {   
        Stack<T> *result = new Stack<T>(*this);
        for (int i = 0; i < stack.size(); i++)
        {
            result->data->Append(stack.data->Get(i));
        }
        return result;
    }

    Stack<T> *GetSubStack(int startIndex, int endIndex)
    {
        Stack<T>* result = new Stack<T>();
        result->data = data->GetSubsequence(startIndex, endIndex);
        return result;
    }
    
    Stack<T>& operator=(const Stack<T> &stack){
        Stack<T> result (stack);
        swap(result);
        return *this;
    }
    
    ~Stack()
    {
        delete data;
    }
};


template <typename T> 
void PrintStack(Stack<T> stack)
    {   
        while (stack.size()!=0)
        {
            std::cout << stack.pop() << " ";
        }
        std::cout << std::endl;
    }
