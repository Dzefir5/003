
#pragma once
#include "Queue.h"
#include <cassert>

void Test_Queue_Constuctors(){
    
    int a[]={1,2,3,4,5,6};

    Queue<int> test2(a,6);
    Queue<int> test1(test2);
    assert(test2.size()==6);
    for(int i=0;i<6;i++){
        assert(test2.pop()==a[i]);
    }
    assert(test1.size()==6);
    for(int i=0;i<6;i++){
        assert(test1.pop()==a[i]);
    }
}

void Test_Queue_Push(){
    
    int a[]={1,2,3,4,5,6};

    Queue<int> test2(a,6);
    test2.push(0);
    assert(test2.size()==7);
    assert(test2.back()==0);
    assert(test2.top()==1);

}
void Test_Queue_Pop(){
    
    int a[]={1,2,3,4,5,6};

    Queue<int> test2(a,6);
    assert(test2.pop()==1);
    assert(test2.size()==5);
}


void Test_Queue_Concat(){
    int f[]={1,2,3,4};
    int m[]={5,6,7};
    int n[]={1,2,3,4,5,6,7};
    Queue<int> testConcat1 (f,4);
    Queue<int> testConcat2 (m,3);
    Queue<int>* testConcat = testConcat1.Concat(testConcat2);
    assert(testConcat->size()==7);
    for(int i=0;i<7;i++){
        assert(testConcat->pop()==n[i]);
    }
}
void Test_Queue_SubQueue(){
    int n[]={1,2,3,4,5,6,7};
    Queue<int> test (n,7);
    int subseq[]={3,4,5,6};
    Queue<int>* testSubSeq = test.GetSubQueue(2,5);
    assert(testSubSeq->size()==4);
    for(int i=0;i<4;i++){
        assert(testSubSeq->pop()==subseq[i]);
    }
}
