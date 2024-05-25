#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include "Stack.h"

int getType(std::string typeName)
{
    std::string lcTypeName = typeName;
    for(int i = 0 ; i<lcTypeName.size();i++){
        lcTypeName[i]=std::tolower(lcTypeName[i]);
    }
    if (lcTypeName == "int") return 1 ; 
    if (lcTypeName == "float") return 2 ; 
    if (lcTypeName == "double") return 3 ; 
    if (lcTypeName == "complex") return 4 ; 
    if (lcTypeName == "char") return 5 ; 

   return 0 ;
}

int getCollection(std::string collectionName)
{
    std::string lcCollectionName = collectionName;
    for(int i = 0 ; i<lcCollectionName.size();i++){
        lcCollectionName[i]=std::tolower(lcCollectionName[i]);
    }
    if (lcCollectionName == "stack") return 1 ; 
    if (lcCollectionName == "queue") return 2 ; 
    if (lcCollectionName == "vector") return 3 ; 
    if (lcCollectionName == "segmenteddeque") return 4 ; 

    return 0 ;
}
int getFuncStack(std::string funcName)
{
    std::string lcfuncName = funcName;
    for(int i = 0 ; i<lcfuncName.size();i++){
        lcfuncName[i]=std::tolower(funcName[i]);
    }
    if (lcfuncName == "push") return 1 ; 
    if (lcfuncName == "pop") return 2 ; 
    if (lcfuncName == "getpeek") return 3 ; 
    if (lcfuncName == "concat") return 4 ;
    if (lcfuncName == "substack") return 5 ;  

    return 0 ;
}

int getFuncQueue(std::string funcName)
{
    std::string lcfuncName = funcName;
    for(int i = 0 ; i<lcfuncName.size();i++){
        lcfuncName[i]=std::tolower(funcName[i]);
    }
    if (lcfuncName == "push") return 1 ; 
    if (lcfuncName == "pop") return 2 ; 
    if (lcfuncName == "top") return 3 ; 
    if (lcfuncName == "back") return 4 ; 
    if (lcfuncName == "concat") return 5 ;
    if (lcfuncName == "subqueue") return 6 ;  

    return 0 ;
}

int getFuncVector(std::string funcName)
{
    std::string lcfuncName = funcName;
    for(int i = 0 ; i<lcfuncName.size();i++){
        lcfuncName[i]=std::tolower(funcName[i]);
    }
    if (lcfuncName == "sum") return 1 ; 
    if (lcfuncName == "multiply") return 2 ; 
    if (lcfuncName == "scalarproduct") return 3 ; 
    if (lcfuncName == "scalar product") return 3 ;  

    return 0 ;
}

int getFuncSegmentedDeque(std::string funcName)
{
    std::string lcfuncName = funcName;
    for(int i = 0 ; i<lcfuncName.size();i++){
        lcfuncName[i]=std::tolower(funcName[i]);
    }
    if (lcfuncName == "getters") return 1 ; 
    if (lcfuncName == "set") return 2 ; 
    if (lcfuncName == "append") return 3 ; 
    if (lcfuncName == "prepend") return 4 ;  
    if (lcfuncName == "popfront") return 5 ; 
    if (lcfuncName == "popback") return 6 ; 
    if (lcfuncName == "removeat") return 7 ; 
    if (lcfuncName == "insertat") return 8 ; 
    if (lcfuncName == "concat") return 9 ; 
    if (lcfuncName == "subdeque") return 10 ; 

    return 0 ;
}

template <typename T>
Stack<T>& StackRead(int count){
    T current;
    Stack<T>* stack = new Stack<T>(); 
    for(int i =0 ; i <count;i++){
        std::cin>>current;
        stack->push(current);
    }
    return *stack;
}



template <typename T>
Queue<T>& QueueRead(int count){
    T current;
    Queue<T>* que = new Queue<T>(); 
    for(int i =0 ; i <count;i++){
        std::cin>>current;
        que->push(current);
    }
    return *que;
}
template <typename T>
Vector<T>& VectorRead(int count){
    T buf[count];
     for(int i =0 ; i <count;i++){
        std::cin>>buf[i];
    }
    return *(new Vector<T>(buf,count));
}

template <typename T>
MutableSegmentedDeque<T>& SegmentedDequeRead(int count){
    T buf[count];
     for(int i =0 ; i <count;i++){
        std::cin>>buf[i];
    }
    auto res = new MutableSegmentedDeque<T>(buf,count);
    return *(res);
}

