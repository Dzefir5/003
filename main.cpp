
#include "Sequence.h"
#include "SegmentedDeque.h"
#include "Testing.h"
#include "UIDemonstration.h"

//clang++ main.cpp -Wall -Wextra -o main.exe

int main(){
    /*
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    std::cout<<"___"<<std::endl;
    MutableSegmentedDeque<int> deq (a, 10);
    std::cout <<deq.chankCount<<std::endl;
    std::cout <<deq.start<<std::endl;
    std::cout <<deq.end<<std::endl;
    deq.PrintSequence();
    std::cout<<std::endl;
    deq.Set(55,3);
    deq.PrintSequence();
    std::cout<<std::endl;
    deq.Append(11);
    deq.Prepend(0);
    deq.PrintSequence();
    std::cout<<std::endl;
    deq.PopFront();
    deq.PopBack();
    deq.PrintSequence();
    std::cout<<std::endl;
    for(int i =0 ; i<4;i++){
        PrintDeque(deq);
        deq.PopBack();
        std::cout<<std::endl;
        
    }
    PrintDeque(deq);
    std::cout<<std::endl;
    deq.InsertAt(8,6);
    PrintDeque(deq);
    std::cout<<std::endl;
    deq.InsertAt(99,6);
    PrintDeque(deq);
    std::cout<<"____"<<std::endl;

    int b[] = {1,2,3,4,5};
    int c[] = {6,7,8,9,10};
    MutableSegmentedDeque<int> deq1 (c,5);
    MutableSegmentedDeque<int> deq2 (b,5);
    PrintDeque(deq1);
    std::cout<<std::endl;
    PrintDeque(deq2);
    std::cout<<std::endl;
    auto deq3 = deq1.Concat(deq2);
    PrintDeque(*deq3);
    std::cout<<std::endl;

    std::cout<<"___"<<std::endl;

    int d[10] = {1,2,3,4,5,6,7,8,9,10};
    std::cout<<"___"<<std::endl;
    MutableSegmentedDeque<int> deq4 (d, 10);
    PrintDeque(deq4);
    std::cout<<std::endl;
    auto deq5 = deq4.GetSubsequence(3,7);
    PrintDeque(*deq5);
    deq5->RemoveAt(2);
    std::cout<<std::endl;
    PrintDeque(*deq5);
    std::cout<<std::endl;

    std::cout<<std::endl;
    std::cout<<"CONSTRUCTORS"<<std::endl;
    int dd[10] = {1,2,3,4,5,6,7,8,9,10};
    std::cout<<"___"<<std::endl;
    MutableSegmentedDeque<int> Deq1 (dd, 10);
    PrintDeque(Deq1);
    MutableSegmentedDeque<int> Deq2(Deq1);
    PrintDeque(Deq2);

    std::cout<<std::endl;
    std::cout<<"SPLIT MUTABLE ARRAY SEQUENCE"<<std::endl;
    int e[]={1,2,3,4,5,6};
    MutableSegmentedDeque<int> testSplit1 (e,6);
    std::cout<<"Sequence до разделения : ";
    PrintDeque(testSplit1);
    std::cout<<std::endl;
    auto func { [](int i){ return i==3;  }};
    auto splitResult1 = testSplit1.Split(func);
    std::cout<<"Результат разделения по элементам кратным 3 : "<<std::endl;
    for(int i=0;i<splitResult1->GetLength();i++){
        splitResult1->Get(i)->PrintSequence();
        std::cout<<std::endl;
    }
    for(int i=0;i<splitResult1->GetLength();i++){
        PrintDeque(*static_cast<MutableSegmentedDeque<int>*>(splitResult1->Get(i)));
        std::cout<<std::endl;
    }
    

    std::cout<<std::endl;
    std::cout<<"SLICE MUTABLE ARRAY SEQUENCE"<<std::endl;
    MutableSegmentedDeque<int> testArraySlice(2,6);
    MutableSegmentedDeque<int> testArraySliceAdd(6,2);
    std::cout<<"Sequence до slice : ";
    PrintDeque(testArraySlice);
    std::cout<<std::endl;
    std::cout<<"Sequence для slice : ";
    PrintDeque( testArraySliceAdd);
    std::cout<<std::endl;

    std::cout<<"Результат после slice начиная с индекса 2, длинною 3: ";
    auto testArraySliceResult1 = testArraySlice.Slice(2,3,testArraySliceAdd);
    PrintDeque(*testArraySliceResult1);
    std::cout<<std::endl<<std::endl;

    int f[10] = {1,2,3,4,5,6,7,8,9,10};
    MutableSegmentedDeque<int> Deqq1 (f, 10);
    PrintDeque(Deqq1);
    std::cout<<std::endl;
    MutableSegmentedDeque<int> Deqq2  = Deqq1;
    PrintDeque(Deqq2);
    std::cout<<std::endl;
    Deqq1+=Deqq2;
    PrintDeque(Deqq1);
    std::cout<<std::endl;
    MutableSegmentedDeque<int> Deqq3 = Deqq1+ Deqq2;
    PrintDeque(Deqq3);
    */
    Test_DynamicArray();
    Test_MapReduce();
    Test_SegmentedDeque();
    demonstartionMapReduce();
    demonstrateMutableSegmentedDeque();




}