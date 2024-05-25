#pragma once
#include <iostream>
#include "ListSequence.h"
#include "MySwap.h"

template <typename T > 
class Queue {
private:
    MutableListSequence<T>* data;
    
    void swap(Queue<T>& toSwap){
        MySwap( data,toSwap.data);
    }
public:
    Queue()
    {
        data = new MutableListSequence<T>();
    }

    Queue(T *array, int count)
    {
        data = new MutableListSequence<T>(array, count);
    }

    Queue(const Sequence<T> &seq)
    {
        data = new MutableListSequence<T>(seq);
    }

    Queue(const Queue<T> &que)
    {
        data = new MutableListSequence<T>();
        for (int i = 0; i < que.data->GetLength(); i++)
        {
            data->Append(que.data->Get(i));
        }
    }

    T top(){
        return data->GetFirst();
    }
    T back(){
        return data->GetLast();
    }

    void push(const T &item)
    {
        this->data->Append(item);
    }

    T pop()
    {   
        if(data->GetLength()>0){
            T result = data->GetFirst();
            data->RemoveAt(0);
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

    Queue<T>* Concat(Queue<T> que)
    { 
        Queue<T>* result = new Queue<T>(*this);
        int counter = que.size();
        for (int i = 0; i < counter; i++)
        {
            result->data->Append(que.pop());
        }
        return result;
    }

    Queue<T>* GetSubQueue(int startIndex, int endIndex)
    {
        Queue<T> *result = new Queue<T>();
        result->data = data->GetSubsequence(startIndex, endIndex);
        return result;
    }

    Queue<T>& operator=(const Queue<T> &que){
        Queue<T> result (que);
        swap(result);
        return *this;
    }

    ~Queue()
    {
        delete data;
    }
};

template <typename T> 
void PrintQueue(Queue<T> que)
{
    int counter = que.size();
    for (int i = 0; i < counter; i++)
    {
        std::cout << que.pop() << " ";
    }
    std::cout << std::endl;
}


