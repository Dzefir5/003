#pragma once

#include "SegmentedDeque.h"
#include "MapReduce.h"
#include <iostream>


void Delimiter(int length,char symbol){
    std::cout<<std::endl;
    for(int i=0;i<length;i++){
        std::cout<<symbol;
    }
    std::cout<<std::endl;
}

void demonstrateMutableSegmentedDeque(){
    int fill1 = 2;
    int fill2 = 5;
    Delimiter(80,'='); 
    std::cout<<"SEGMENTED DEQUE"<<std::endl<<std::endl;
    std::cout<<"Первый заполняющий элемент : "<<fill1<<std::endl;
    std::cout<<"Второй заполняющий элемент : "<<fill2<<std::endl;
    MutableSegmentedDeque<int> testlist1(fill1,5);
    MutableSegmentedDeque<int> testlist2(fill2,7);
    std::cout<<"Первый Deque размера 5 : ";
    testlist1.PrintSequence();
    std::cout<<std::endl;
    PrintDeque(testlist1);
    std::cout<<std::endl;
    std::cout<<"Второй Deque размера 7 : ";
    testlist2.PrintSequence();
    std::cout<<std::endl;
    PrintDeque(testlist2);
    std::cout<<std::endl;

    Delimiter(80,'=');

    std::cout<<std::endl;
    std::cout<<"SET FUNCTION "<<std::endl;
    testlist1.Set(10,3);
    testlist2[3]=-30;
    std::cout<<"Первый Deque с 10 в четвёртом элементе : ";
    testlist1.PrintSequence();
    std::cout<<std::endl;
    PrintDeque(testlist1);
    std::cout<<std::endl;
    std::cout<<"Второй Deque с -30 в четвёртом элементе : ";
    testlist2.PrintSequence();
    std::cout<<std::endl;
    PrintDeque(testlist2);
    std::cout<<std::endl;

    Delimiter(80,'=');

    std::cout<<std::endl;
    //Copy constructor test
    std::cout<<"APPEND SEGMENTED DEQUE"<<std::endl;
    MutableSegmentedDeque<int>* testlist4 =  new MutableSegmentedDeque<int>(testlist1);
    std::cout<<"Deque до Append :";
    testlist4->PrintSequence();
    std::cout<<std::endl;
    PrintDeque(*testlist4);
    std::cout<<std::endl;
    testlist4->Append(10);
    std::cout<<"Deque после Append(10) :";
    testlist4->PrintSequence();
    std::cout<<std::endl;
    PrintDeque(*testlist4);
    std::cout<<std::endl;

    Delimiter(80,'=');

    std::cout<<std::endl;
    std::cout<<"SEGMENTED DEQUE CONCAT"<<std::endl;
    MutableSegmentedDeque<int>* testlist3 = testlist1.Concat(testlist2);
    std::cout<<"Первый Deque : ";
    testlist1.PrintSequence();
    std::cout<<std::endl;
    PrintDeque(testlist1);
    std::cout<<std::endl;
    std::cout<<"Второй Deque : ";
    testlist2.PrintSequence();
    std::cout<<std::endl;
    PrintDeque(testlist2);
    std::cout<<std::endl;
    std::cout<<"Результат конкатенации : ";
    testlist3->PrintSequence();
    std::cout<<std::endl;
    PrintDeque(*testlist3);
    std::cout<<std::endl;

    Delimiter(80,'=');

    std::cout<<std::endl;
    std::cout<<"SEGMENTED DEQUE SUBSEQUENCE"<<std::endl;
    std::cout<<"Deque из которой берётся подпоследовательность : ";
    testlist3->PrintSequence();
    std::cout<<std::endl;
    PrintDeque(*testlist3);
    std::cout<<std::endl;
    MutableSegmentedDeque<int>* testlist5 =testlist3->GetSubsequence(2,8);
    std::cout<<"Результирующая подпоследовательность с третьего по девятый элемент  : ";
    testlist5->PrintSequence();
    std::cout<<std::endl;
    PrintDeque(*testlist5);
    std::cout<<std::endl;

    Delimiter(80,'=');

    std::cout<<std::endl;
    std::cout<<"SPLIT SEGMENTED DEQUE"<<std::endl;
    int b[]={1,2,3,4,5,6};
    MutableSegmentedDeque<int> testSplit1 (b,6);
    std::cout<<"Deque до разделения : ";
    testSplit1.PrintSequence();
    std::cout<<std::endl;
    PrintDeque(testSplit1);
    std::cout<<std::endl;
    auto func { [](int i){ return i==3;  }};
    auto splitResult1 = testSplit1.Split(func);
    std::cout<<"Результат разделения по элементам кратным 3 : "<<std::endl;
    for(int i=0;i<splitResult1->GetLength();i++){
        splitResult1->Get(i)->PrintSequence();
        std::cout<<std::endl;
        PrintDeque( *(static_cast<SegmentedDeque<int>*>(splitResult1->Get(i)) ) );
        std::cout<<std::endl;
    }

    Delimiter(80,'=');

    std::cout<<std::endl;
    std::cout<<"SLICE SEGMENTED DEQUE"<<std::endl;
    MutableSegmentedDeque<int> testArraySlice(2,6);
    MutableSegmentedDeque<int> testArraySliceAdd(6,2);
    std::cout<<"Deque до slice : ";
    testArraySlice.PrintSequence();
    std::cout<<std::endl;
    PrintDeque(testArraySlice);
    std::cout<<std::endl;
    std::cout<<"Deque для slice : ";
    testArraySliceAdd.PrintSequence();
    std::cout<<std::endl;
    PrintDeque(testArraySliceAdd);
    std::cout<<std::endl;

    std::cout<<"Результат после slice начиная с индекса 2, длинною 3: ";
    auto testArraySliceResult1 = testArraySlice.Slice(2,3,testArraySliceAdd);
    testArraySliceResult1->PrintSequence();
    std::cout<<std::endl;
    PrintDeque(*testArraySliceResult1);

    Delimiter(80,'=');
}


int testForMap(int i ) 
{ 
    return 2*i;  
}
bool testForWhere(int i){
    return i%2==0;
}
int testForReduce(int a,int b ) 
{ 
    return a+b;  
}
void demonstartionMapReduce(){
    //auto testForMap { [](int i){ return 2*i;  }};
    Delimiter(80,'='); 
    std::cout<<"MAP FUNCTION"<<std::endl;
    std::cout<<"Исходный Sequence  : ";
    int b[]={1,2,3,4,5,6};
    MutableSegmentedDeque<int> testMap1(b,6);
    testMap1.PrintSequence();
    std::cout<<std::endl;

    MutableSegmentedDeque<int> mapResult1 = map(testMap1,&testForMap);
    std::cout<<"Результат операции map(умножает исходное на 2) : ";
    mapResult1.PrintSequence();
    std::cout<<std::endl;

    std::cout<<std::endl;
    std::cout<<"WHERE FUNCTION"<<std::endl;
    int a[4]={1,2,3,4};
    MutableSegmentedDeque<int> testWhere(a,4);
    std::cout<<"Исходный Deque  : ";
    testWhere.PrintSequence();
    std::cout<<std::endl;
    std::cout<<"Результат выборки where по чётным числам : ";
    MutableSegmentedDeque<int> whereResult = where(testWhere,&testForWhere);
    whereResult.PrintSequence();
    std::cout<<std::endl;

    std::cout<<std::endl;
    std::cout<<"REDUCE FUNCTION"<<std::endl;
    int c[4]={1,2,3,4};
    MutableSegmentedDeque<int> testReduce(c,4);
    std::cout<<"Исходный Deque  : ";
    int start =0;
    testReduce.PrintSequence();
    std::cout<<std::endl;
    std::cout<<"Результат reduce от функции суммирования : ";
    auto ReduceResult = reduce(testWhere,&testForReduce,start);
    std::cout<<ReduceResult<<std::endl;


    std::cout<<std::endl;        
    std::cout<<"ZIP TEST"<<std::endl;
    MutableSegmentedDeque<int> test_1(1,2);
    test_1[0]=1;
    test_1[1]=2;
    std::cout<<"Первый Deque  : ";
    test_1.PrintSequence();
    std::cout<<std::endl;
    MutableSegmentedDeque<double> test_2(2.0,3);
    test_2[0]=3.1;
    test_2[1]=4.2;
    test_2[2]=5.2;
    std::cout<<"Второй Deque  : ";
    test_2.PrintSequence();
    std::cout<<std::endl;
    MutableSegmentedDeque<char> test_3('a',2);
    test_3[0]='a';
    test_3[1]='b';
    std::cout<<"Третий Deque  : ";
    test_3.PrintSequence();
    std::cout<<std::endl;

    auto test_4 = zip<int,double,char>(test_1,test_2,test_3) ;
    std::cout<<"Результат функции ZIP : "<<std::endl;
    for(int i =0; i<test_4.GetLength();i++){
        std::cout<<"Элемент номер "<<i<<" : ";
        printTuple( test_4.Get(i) );
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"UNZIP TEST"<<std::endl;
    std::cout<<"Входной  ZipSequence : "<<std::endl;
    for(int i =0; i<test_4.GetLength();i++){
        std::cout<<"Элемент номер "<<i<<" : ";
        printTuple( test_4.Get(i) );
        std::cout<<std::endl;
    }
    
    auto TEST =  unzip(test_4);
    std::cout<<"Результат функции UNZIP : "<<std::endl;

    std::cout<<"Первый Deque : ";
    Get<0>(TEST)->PrintSequence();
    std::cout<<std::endl;

    std::cout<<"Второй Deque : ";
    Get<1>(TEST)->PrintSequence();
    std::cout<<std::endl;

    std::cout<<"Третий Deque : ";
    Get<2>(TEST)->PrintSequence();
    std::cout<<std::endl;
    
 
}