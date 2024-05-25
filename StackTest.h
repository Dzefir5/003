
#pragma once
#include "Stack.h"
#include <cassert>

void Test_Stack_Constuctors(){
    
    int a[]={1,2,3,4,5,6};

    Stack<int> test2(a,6);
    Stack<int> test1(test2);
    assert(test2.size()==6);
    for(int i=0;i<6;i++){
        assert(test2.pop()==a[5-i]);
    }
    assert(test1.size()==6);
    for(int i=0;i<6;i++){
        assert(test1.pop()==a[5-i]);
    }
}

void Test_Stack_Push(){
    
    int a[]={1,2,3,4,5,6};

    Stack<int> test2(a,6);
    test2.push(0);
    assert(test2.size()==7);
    assert(test2.pop()==0);
    for(int i=0;i<6;i++){
        assert(test2.pop()==a[5-i]);
    }
}
void Test_Stack_Pop(){
    
    int a[]={1,2,3,4,5,6};

    Stack<int> test2(a,6);
    assert(test2.pop()==6);
    assert(test2.size()==5);
}


void Test_Stack_Concat(){
    int f[]={1,2,3,4};
    int m[]={5,6,7};
    int n[]={1,2,3,4,5,6,7};
    Stack<int> testConcat1 (f,4);
    Stack<int> testConcat2 (m,3);
    Stack<int>* testConcat = testConcat1.Concat(testConcat2);
    assert(testConcat->size()==7);
    for(int i=0;i<7;i++){
        assert(testConcat->pop()==n[6-i]);
    }
}
void Test_Stack_SubStack(){
    int n[]={1,2,3,4,5,6,7};
    Stack<int> test (n,7);
    int subseq[]={3,4,5,6};
    Stack<int>* testSubSeq = test.GetSubStack(2,5);
    assert(testSubSeq->size()==4);
    for(int i=0;i<4;i++){
        assert(testSubSeq->pop()==subseq[3-i]);
    }
}
