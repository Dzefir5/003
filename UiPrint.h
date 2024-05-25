#pragma once
#include <iostream>
#include "UiFuncs.h"
#include "Stack.h"
#include "Queue.h"
#include "SegmentedDeque.h"
#include "Vector.h"


void Delimeter(int count , char symbol){
    std::cout<<std::endl;
    for(int i=0;i<count;i++){
        std::cout<<symbol;
    }
    std::cout<<std::endl;
}
void Delimeter(int count , std::string string){
    std::cout<<std::endl;
    for(int i=0;i<string.length()/count;i++){
        std::cout<<string;
    }
    std::cout<<std::endl;
}
void PrintTypes(){
    std::cout<<std::endl;
    std::cout << "Available collections :" <<std::endl;
    std::cout <<  "     Stack : int , float , double " <<std::endl;
    std::cout <<  "     Queue : int , float , double " <<std::endl;
    std::cout <<  "     SegmentedDeque : int , float , double " <<std::endl;
    std::cout <<  "     Vector : int , float , double " <<std::endl;
    std::cout<<std::endl;
}


void PrintFuncStack(){
    std::cout<<std::endl;
    std::cout << "Available functions :" <<std::endl;
    std::cout <<  "     Push" <<std::endl;
    std::cout <<  "     Pop" <<std::endl;
    std::cout <<  "     GetPeek" <<std::endl;
    std::cout <<  "     Concat" <<std::endl;
    std::cout <<  "     SubStack" <<std::endl;
}
void PrintFuncSegmentedDeque(){
    std::cout<<std::endl;
    std::cout << "Available functions :" <<std::endl;
    std::cout <<  "     Getters" <<std::endl;
    std::cout <<  "     Set" <<std::endl;
    std::cout <<  "     Append" <<std::endl;
    std::cout <<  "     Prepend" <<std::endl;
    std::cout <<  "     PopFront" <<std::endl;
    std::cout <<  "     PopBack" <<std::endl;
    std::cout <<  "     RemoveAt" <<std::endl;
    std::cout <<  "     InsertAt" <<std::endl;
    std::cout <<  "     Concat" <<std::endl;
    std::cout <<  "     SubDeque" <<std::endl;
}

void PrintFuncQueue(){
    std::cout<<std::endl;
    std::cout << "Available functions :" <<std::endl;
    std::cout <<  "     Push" <<std::endl;
    std::cout <<  "     Pop" <<std::endl;
    std::cout <<  "     Top" <<std::endl;
    std::cout <<  "     Back" <<std::endl;
    std::cout <<  "     Concat" <<std::endl;
    std::cout <<  "     SubQueue" <<std::endl;
}

void PrintFuncVector(){
    std::cout<<std::endl;
    std::cout << "Available functions :" <<std::endl;
    std::cout <<  "     Sum" <<std::endl;
    std::cout <<  "     Multiply" <<std::endl;
    std::cout <<  "     Scalar Product" <<std::endl;
}
template <typename T>
void StackPush(){
    std::cout << "Введите размер стека" << std::endl;
    int size = 0;
    std::cin >> size;
    std::cout << "Введите элементы стэка " << std::endl;
    Stack<T> stk = StackRead<T>(size);
    std::cout << "Ваш стэк ";
    PrintStack(stk);
    std::cout << "Введите количество элементов для push" << std::endl;
    int sizePush = 0;
    std::cin >> sizePush;
    T current ;
    for (int i = 0; i < sizePush; i++)
    {
        std::cin >> current;
        stk.push(current);
    }
    std::cout << "Ваш стэк после push : ";
    PrintStack(stk);
}

template <typename T>
void StackPop(){
    std::cout << "Введите размер стека" << std::endl;
    int size = 0;
    std::cin >> size;
    std::cout << "Введите элементы стэка " << std::endl;
    Stack<T> stk = StackRead<T>(size);
    std::cout << "Ваш стэк ";
    PrintStack(stk);
    std::cout << "Введите количество элементов для pop" << std::endl;
    int sizePop = 0;
    std::cin >> sizePop;
    for (int i = 0; i < sizePop; i++)
    {
        stk.pop();
    }
    std::cout << "Ваш стэк после pop : ";
    PrintStack(stk);
}

template <typename T>
void StackPeek(){
    std::cout << "Введите размер стека" << std::endl;
    int size = 0;
    std::cin >> size;
    std::cout << "Введите элементы стэка " << std::endl;
    Stack<T> stk = StackRead<T>(size);
    std::cout << "Ваш стэк ";
    PrintStack(stk);
    std::cout<< "Элемент полученый Peek : " << stk.peek()<<std::endl;
}    
template <typename T>
void StackConcat(){
    std::cout << "Введите размер стека 1" << std::endl;
    int size1 = 0;
    std::cin >> size1;
    std::cout << "Введите элементы стэка 1" << std::endl;
    Stack<T> stk1 = StackRead<T>(size1);
    std::cout << "Введите размер стека 2" << std::endl;
    int size2 = 0;
    std::cin >> size2;
    std::cout << "Введите элементы стэка 2" << std::endl;
    Stack<T> stk2 = StackRead<T>(size2);
    std::cout << "Ваши стэки ";
    PrintStack(stk1);
    PrintStack(stk2);
    std::cout << "Результат конкатенации :" << std::endl;
    Stack<T>* stk = stk1.Concat(stk2);
    PrintStack(*stk);
}
template <typename T>
void StackSubStack(){
    std::cout << "Введите размер стека " << std::endl;
    int size = 0;
    std::cin >> size;
    std::cout << "Введите элементы стэка " << std::endl;
    Stack<T> stk = StackRead<T>(size);
    std::cout << "Ваш стэк ";
    PrintStack(stk);
    int index1 = 0;
    int index2 = 0;
    std::cout << "Введите начальный индекс : " << std::endl;
    std::cin>>index1;
    std::cout << "Введите конечный  индекс : " << std::endl;
    std::cin>>index2;
    std::cout << "Результат  :" << std::endl;
    Stack<T>* stk1 = stk.GetSubStack(index1,index2);
    PrintStack(*stk1);
}

template <typename T>
void QueuePush(){
    std::cout << "Введите размер очереди" << std::endl;
    int size = 0;
    std::cin >> size;
    std::cout << "Введите элементы очереди " << std::endl;
    Queue<T> stk = QueueRead<T>(size);
    std::cout << "Ваша очередь ";
    PrintQueue(stk);
    std::cout << "Введите количество элементов для push" << std::endl;
    int sizePush = 0;
    std::cin >> sizePush;
    T current ;
    for (int i = 0; i < sizePush; i++)
    {
        std::cin >> current;
        stk.push(current);
    }
    std::cout << "Ваша очередь после push : ";
    PrintQueue(stk);
}

template <typename T>
void QueuePop(){
    std::cout << "Введите размер очереди" << std::endl;
    int size = 0;
    std::cin >> size;
    std::cout << "Введите элементы очереди " << std::endl;
    Queue<T> stk = QueueRead<T>(size);
    std::cout << "Ваша очередь ";
    PrintQueue(stk);
    std::cout << "Введите количество элементов для pop" << std::endl;
    int sizePop = 0;
    std::cin >> sizePop;
    for (int i = 0; i < sizePop; i++)
    {
        stk.pop();
    }
    std::cout << "Ваша очередь после pop : ";
    PrintQueue(stk);
}

template <typename T>
void QueueTop(){
    std::cout << "Введите размер очереди" << std::endl;
    int size = 0;
    std::cin >> size;
    std::cout << "Введите элементы очереди " << std::endl;
    Queue<T> stk = QueueRead<T>(size);
    std::cout << "Ваша очередь ";
    PrintQueue(stk);
    std::cout<< "Элемент полученый Top : " << stk.top()<<std::endl;
}   
template <typename T>
void QueueBack(){
    std::cout << "Введите размер очереди" << std::endl;
    int size = 0;
    std::cin >> size;
    std::cout << "Введите элементы очереди " << std::endl;
    Queue<T> stk = QueueRead<T>(size);
    std::cout << "Ваша очередь ";
    PrintQueue(stk);
    std::cout<< "Элемент полученый Back : " << stk.back()<<std::endl;
}    

template <typename T>
void QueueConcat(){
    std::cout << "Введите размер очереди 1" << std::endl;
    int size1 = 0;
    std::cin >> size1;
    std::cout << "Введите элементы очереди 1" << std::endl;
    Queue<T> stk1 = QueueRead<T>(size1);
    std::cout << "Введите размер очереди 2" << std::endl;
    int size2 = 0;
    std::cin >> size2;
    std::cout << "Введите элементы очереди 2" << std::endl;
    Queue<T> stk2 = QueueRead<T>(size2);
    std::cout << "Ваши очереди ";
    PrintQueue(stk1);
    PrintQueue(stk2);
    std::cout << "Результат конкатенации :" << std::endl;
    Queue<T>* stk = stk1.Concat(stk2);
    PrintQueue(*stk);
}
template <typename T>
void QueueSubQueue(){
    std::cout << "Введите размер очереди " << std::endl;
    int size = 0;
    std::cin >> size;
    std::cout << "Введите элементы очереди " << std::endl;
    Queue<T> stk = QueueRead<T>(size);
    std::cout << "Ваша очередь ";
    PrintQueue(stk);
    int index1 = 0;
    int index2 = 0;
    std::cout << "Введите начальный индекс : " << std::endl;
    std::cin>>index1;
    std::cout << "Введите конечный  индекс : " << std::endl;
    std::cin>>index2;
    std::cout << "Результат  :" << std::endl;
    Queue<T>* stk1 = stk.GetSubQueue(index1,index2);
    PrintQueue(*stk1);
}


template <typename T>
void VectorSum(){
    std::cout << "Введите размер векторов " << std::endl;
    int size = 0;
    std::cin >> size;
    std::cout << "Введите элементы вектора 1" << std::endl;
    Vector<T> stk1 = VectorRead<T>(size);
    std::cout << "Введите элементы вектора 2" << std::endl;
    Vector<T> stk2 = VectorRead<T>(size);
    std::cout << "Ваши вектора ";
    PrintVector(stk1);
    PrintVector(stk2);
    std::cout << "Результат суммирования :" << std::endl;
    Vector<T> stk = stk1 + stk2;
    PrintVector(stk);
}

template <typename T>
void ScalProd(){
    std::cout << "Введите размер векторов " << std::endl;
    int size = 0;
    std::cin >> size;
    std::cout << "Введите элементы вектора 1" << std::endl;
    Vector<T> stk1 = VectorRead<T>(size);
    std::cout << "Введите элементы вектора 2" << std::endl;
    Vector<T> stk2 = VectorRead<T>(size);
    std::cout << "Ваши вектора ";
    PrintVector(stk1);
    PrintVector(stk2);
    std::cout << "Результат суммирования :" << std::endl;
    T stk =  stk1 * stk2;
    std::cout<<stk<<std::endl;
}

template <typename T>
void VectorMult(){
    std::cout << "Введите размер вектора " << std::endl;
    int size = 0;
    std::cin >> size;
    std::cout << "Введите элементы вектора " << std::endl;
    Vector<T> vec = VectorRead<T>(size);
    std::cout << "Введите число для умножения " << std::endl;
    T number ;
    std::cin>>number;
    std::cout << "Ваш вектор ";
    PrintVector(vec);
    std::cout << "Результат умножения :" << std::endl;
    Vector<T> vecRes = vec*number;
    PrintVector(vecRes);
}

template <typename T>
void SegmentedDequeGetters(){
    std::cout << "Введите размер дэка " << std::endl;
    int size = 0;
    std::cin >> size;
    MutableSegmentedDeque<T> deq = SegmentedDequeRead<T>(size);
    std::cout << "Ваш дэк ";
    PrintDeque(deq);
    std::cout << "Первый элемент :" << std::endl;
    std::cout << deq.GetFirst() << std::endl;
    std::cout << "Последний элемент :" << std::endl;
    std::cout << deq.GetLast() << std::endl;

    std::cout << "Введите индекс для получения значения " << std::endl;
    int index = 0;
    std::cin >> index;
    std::cout << "Элемент по индекусу "<<index<<":" << std::endl;
    std::cout << deq.Get(index) << std::endl;

}

template <typename T>
void SegmentedDequeSet(){
    std::cout << "Введите размер дэка " << std::endl;
    int size = 0;
    std::cin >> size;
    MutableSegmentedDeque<T> deq = SegmentedDequeRead<T>(size);
    std::cout << "Ваш дэк ";
    PrintDeque(deq);
    std::cout << "Введите количество элементов для set : " << std::endl;
    int count = 0;
    std::cin >> count;
    for(int i=0 ; i<count;i++){
        std::cout << "Введите индекс для set : " << std::endl;
        int index = 0;
        std::cin >> index;
        std::cout << "Введите элемент для set : " << std::endl;
        T current = 0;
        std::cin >> current;
        deq.Set(current,index);
    }
    std::cout << "Ваш дэк результат";
    PrintDeque(deq);
}

template <typename T>
void SegmentedDequeAppend(){
    std::cout << "Введите размер дэка " << std::endl;
    int size = 0;
    std::cin >> size;
    MutableSegmentedDeque<T> deq = SegmentedDequeRead<T>(size);
    std::cout << "Ваш дэк ";
    PrintDeque(deq);
    std::cout << "Введите количество элементов для append : " << std::endl;
    int count = 0;
    std::cin >> count;
    for(int i=0 ; i<count;i++){
        std::cout << "Введите элемент для append : " << std::endl;
        T current = 0;
        std::cin >> current;
        deq.Append(current);
    }
    std::cout << "Ваш дэк результат";
    PrintDeque(deq);
}

template <typename T>
void SegmentedDequePrepend(){
    std::cout << "Введите размер дэка " << std::endl;
    int size = 0;
    std::cin >> size;
    MutableSegmentedDeque<T> deq = SegmentedDequeRead<T>(size);
    std::cout << "Ваш дэк ";
    PrintDeque(deq);
    std::cout << "Введите количество элементов для prepend : " << std::endl;
    int count = 0;
    std::cin >> count;
    for(int i=0 ; i<count;i++){
        std::cout << "Введите элемент для prepend : " << std::endl;
        T current = 0;
        std::cin >> current;
        deq.Prepend(current);
    }
    std::cout << "Ваш дэк результат";
    PrintDeque(deq);
}

template <typename T>
void SegmentedDequePopFront(){
    std::cout << "Введите размер дэка " << std::endl;
    int size = 0;
    std::cin >> size;
    MutableSegmentedDeque<T> deq = SegmentedDequeRead<T>(size);
    std::cout << "Ваш дэк ";
    PrintDeque(deq);
    std::cout << "Введите количество элементов для popfront : " << std::endl;
    int count = 0;
    std::cin >> count;
    for(int i=0 ; i<count;i++){
        deq.PopFront();
    }
    std::cout << "Ваш дэк результат";
    PrintDeque(deq);
}

template <typename T>
void SegmentedDequePopBack(){
    std::cout << "Введите размер дэка " << std::endl;
    int size = 0;
    std::cin >> size;
    MutableSegmentedDeque<T> deq = SegmentedDequeRead<T>(size);
    std::cout << "Ваш дэк ";
    PrintDeque(deq);
    std::cout << "Введите количество элементов для popback : " << std::endl;
    int count = 0;
    std::cin >> count;
    for(int i=0 ; i<count;i++){
        deq.PopBack();
    }
    std::cout << "Ваш дэк результат";
    PrintDeque(deq);
}

template <typename T>
void SegmentedDequeRemoveAt(){
    std::cout << "Введите размер дэка " << std::endl;
    int size = 0;
    std::cin >> size;
    MutableSegmentedDeque<T> deq = SegmentedDequeRead<T>(size);
    std::cout << "Ваш дэк ";
    PrintDeque(deq);
    std::cout << "Введите количество элементов для removeAt : " << std::endl;
    int count = 0;
    std::cin >> count;
    for(int i=0 ; i<count;i++){
        std::cout << "Введите индекс для remove : " << std::endl;
        int index = 0;
        std::cin >> index;
        deq.RemoveAt(index);
        std::cout << "Ваш дэк результат";
        PrintDeque(deq);
    }
  
}
template <typename T>
void SegmentedDequeInsertAt(){
    std::cout << "Введите размер дэка " << std::endl;
    int size = 0;
    std::cin >> size;
    MutableSegmentedDeque<T> deq = SegmentedDequeRead<T>(size);
    std::cout << "Ваш дэк ";
    PrintDeque(deq);
    std::cout << "Введите количество элементов для InsertAt : " << std::endl;
    int count = 0;
    std::cin >> count;
    for(int i=0 ; i<count;i++){
        std::cout << "Введите индекс для InsertAt : " << std::endl;
        int index = 0;
        std::cin >> index;
        std::cout << "Введите Элемент для InsertAt : " << std::endl;
        T current = 0;
        std::cin >> current;
        deq.InsertAt(current,index);
        std::cout << "Ваш дэк результат";
        PrintDeque(deq);
    }
  
}
template <typename T>
void SegmentedDequeConcat(){
    std::cout << "Введите размер дэка 1 " << std::endl;
    int size1 = 0;
    std::cin >> size1;
    MutableSegmentedDeque<T> deq1 = SegmentedDequeRead<T>(size1);
    std::cout << "Введите размер дэка 2 " << std::endl;
    int size2 = 0;
    std::cin >> size2;
    MutableSegmentedDeque<T> deq2 = SegmentedDequeRead<T>(size2);
    std::cout << "Ваши дэки ";
    PrintDeque(deq1);
    PrintDeque(deq2);
    MutableSegmentedDeque<T>* deq = deq1.Concat(deq2);
    std::cout << "Ваш дэк результат";
    PrintDeque(*deq);
  
}
template <typename T>
void SegmentedDequeSubDeque(){
    std::cout << "Введите размер дэка " << std::endl;
    int size = 0;
    std::cin >> size;
    MutableSegmentedDeque<T> deq = SegmentedDequeRead<T>(size);
    std::cout << "Ваш дэк ";
    PrintDeque(deq);
    int index1 = 0;
    int index2 = 0;
    std::cout << "Введите начальный индекс : " << std::endl;
    std::cin>>index1;
    std::cout << "Введите конечный  индекс : " << std::endl;
    std::cin>>index2;
    std::cout << "Результат  :" << std::endl;
    MutableSegmentedDeque<T>* deqres = deq.GetSubsequence(index1,index2);
  
}




void switchCollection(int CollectionId, int TypeId)
{   
    Delimeter(80,'=');
    switch (CollectionId)
    {
    case 1:
    {
        PrintFuncStack();
        std::cout << "Введите название функции : ";
        std::string funcName;
        std::cin >> funcName;
        while(getFuncStack(funcName)==0){
                std::cout<<"Wrong command - Try Again"<<std::endl;
                std::cin >> funcName;
        }
        switch (getFuncStack(funcName))
        {
        case 1:
        {   
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                StackPush<int>();
                break;
            case 2: 
                StackPush<float>();
                break;
            case 3:
                StackPush<double>();
                break;
            default:
            }
            break;
        }
        case 2:
        {
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                StackPop<int>();
                break;
            case 2:
                StackPop<float>();
                break;
            case 3:
                StackPop<double>();
                break;
            default:
            }
            break;
        }
        case 3:
        {
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                StackPeek<int>();
                break;
            case 2:
                StackPeek<float>();
                break;
            case 3:
                StackPeek<double>();
                break;
            default:
            }
            break;
        }
        case 4:
        {
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                StackConcat<int>();
                break;
            case 2:
                StackConcat<float>();
                break;
            case 3:
                StackConcat<double>();
                break;
            default:
            }
            break;
        }
        case 5:
        {
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                StackSubStack<int>();
                break;
            case 2:
                StackSubStack<float>();
                break;
            case 3:
                StackSubStack<double>();
                break;
            default:
            }
            break;
        }
        }
    }
    case 2:
    {   
        PrintFuncQueue();
        std::cout << "Введите название функции : ";
        std::string funcName;
        std::cin >> funcName;
        while(getFuncQueue(funcName)==0){
                std::cout<<"Wrong command - Try Again"<<std::endl;
                std::cin >> funcName;
        }
        switch (getFuncQueue(funcName))
        {
        case 1:
        {
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                QueuePush<int>();
                break;
            case 2:
                QueuePush<float>();
                break;
            case 3:
                QueuePush<double>();
                break;
            default:
            }
            break;
        }
        case 2:
        {   
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                QueuePop<int>();
                break;
            case 2:
                QueuePop<float>();
                break;
            case 3:
                QueuePop<double>();
                break;
            default:
            }
            break;
        }
        case 3:
        {
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                QueueTop<int>();
                break;
            case 2:
                QueueTop<float>();
                break;
            case 3:
                QueueTop<double>();
                break;
            default:
            }
            break;
        }
        case 5:
        {   
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                QueueConcat<int>();
                break;
            case 2:
                QueueConcat<float>();
                break;
            case 3:
                QueueConcat<double>();
                break;
            default:
            }
            break;
        }
        case 6:
        {   
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                QueueSubQueue<int>();
                break;
            case 2:
                QueueSubQueue<float>();
                break;
            case 3:
                QueueSubQueue<double>();
                break;
            default:
            }
            break;
        }
        case 4:
        {
            switch (TypeId)
            {
            case 1:
                QueueBack<int>();
                break;
            case 2:
                QueueBack<float>();
                break;
            case 3:
                QueueBack<double>();
                break;
            default:
            }
            break;
        }
        }
    }
    break;
    case 3:
    {
        PrintFuncVector();
        std::cout << "Введите название функции : ";
        std::string funcName;
        std::cin >> funcName;
        while(getFuncVector(funcName)==0){
                std::cout<<"Wrong command - Try Again"<<std::endl;
                std::cin >> funcName;
        }
        switch (getFuncVector(funcName))
        {
        case 1:
        {   
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                VectorSum<int>();
                break;
            case 2:
                VectorSum<float>();
                break;
            case 3:
                VectorSum<double>();
                break;
            default:
            }
            break;
        }
        case 2:
        {   
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                VectorMult<int>();
                break;
            case 2:
                VectorMult<float>();
                break;
            case 3:
                VectorMult<double>();
                break;
            default:
            }
            break;
        }
        case 3:
        {
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                ScalProd<int>();
                break;
            case 2:
                ScalProd<float>();
                break;
            case 3:
                ScalProd<double>();
                break;
            default:
            }
            break;
        }
        }
    }
    break;
    case 4:
        PrintFuncSegmentedDeque();
        std::cout << "Введите название функции : ";
        std::string funcName;
        std::cin >> funcName;
        while(getFuncSegmentedDeque(funcName)==0){
                std::cout<<"Wrong command - Try Again"<<std::endl;
                std::cin >> funcName;
        }
        switch (getFuncSegmentedDeque(funcName))
        {
        case 1:
        {   
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                SegmentedDequeGetters<int>();
                break;
            case 2:
                SegmentedDequeGetters<float>();
                break;
            case 3:
                SegmentedDequeGetters<double>();
                break;
            default:

            }
            break;
        }
        case 2:
        {   
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                SegmentedDequeSet<int>();
                break;
            case 2:
                SegmentedDequeSet<float>();
                break;
            case 3:
                SegmentedDequeSet<double>();
                break;
            default:
            }
            break;
        }
        case 3:
        {
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                SegmentedDequeAppend<int>();
                break;
            case 2:
                SegmentedDequeAppend<float>();
                break;
            case 3:
                SegmentedDequeAppend<double>();
                break;
            default:
            }
            break;
        }
        case 4:
        {
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                SegmentedDequePrepend<int>();
                break;
            case 2:
                SegmentedDequePrepend<float>();
                break;
            case 3:
                SegmentedDequePrepend<double>();
                break;
            default:
            }
            break;
        }
        case 5:
        {
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                SegmentedDequePopFront<int>();
                break;
            case 2:
                SegmentedDequePopFront<float>();
                break;
            case 3:
                SegmentedDequePopFront<double>();
                break;
            default:
            }
            break;
        }
        case 6:
        {
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                SegmentedDequePopBack<int>();
                break;
            case 2:
                SegmentedDequePopBack<float>();
                break;
            case 3:
                SegmentedDequePopBack<double>();
                break;
            default:
            }
            break;
        }
        case 7:
        {
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                SegmentedDequeRemoveAt<int>();
                break;
            case 2:
                SegmentedDequeRemoveAt<float>();
                break;
            case 3:
                SegmentedDequeRemoveAt<double>();
                break;
            default:
            }
            break;
        }
        case 8:
        {
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                SegmentedDequeInsertAt<int>();
                break;
            case 2:
                SegmentedDequeInsertAt<float>();
                break;
            case 3:
                SegmentedDequeInsertAt<double>();
                break;
            default:
            }
            break;
        }
        case 9:
        {
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                SegmentedDequeConcat<int>();
                break;
            case 2:
                SegmentedDequeConcat<float>();
                break;
            case 3:
                SegmentedDequeConcat<double>();
                break;
            default:
            }
            break;
        }
        case 10:
        {
            Delimeter(80,'=');
            switch (TypeId)
            {
            case 1:
                SegmentedDequeSubDeque<int>();
                break;
            case 2:
                SegmentedDequeSubDeque<float>();
                break;
            case 3:
                SegmentedDequeSubDeque<double>();
                break;
            default:
            }
            break;
        }
        }
    }
}
