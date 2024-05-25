#pragma once
#include "Vector.h"
#include <cassert>

void Test_Vector_Constuctors(){
    
    int a[]={1,2,3,4,5,6};

    Vector<int> test2(a,6);
    Vector<int> test1(test2);
    assert(test2.Size()==6);
    for(int i=0;i<6;i++){
        assert(test2.Get(i)==a[i]);
    }
    assert(test1.Size()==6);
    for(int i=0;i<6;i++){
        assert(test1.Get(i)==a[i]);
    }
}

void Test_Vector_Sum(){
    
    int a[]={1,2,3,4,5,6};
    int b[]={1,2,3,4,5,6};

    Vector<int> test2(b,6);
    Vector<int> test1(a,6);
    Vector<int> test3 = test1 + test2;
    for(int i=0;i<6;i++){
        assert(test3.Get(i)==a[i]+b[i]);
    }
}

void Test_Vector_Mult(){
    
    int a[]={1,2,3,4,5,6};
    Vector<int> test1(a,6);
    Vector<int> test3 = test1 * 2;
    for(int i=0;i<6;i++){
        assert(test3.Get(i)==a[i]*2);
    }
}
void Test_Vector_ScalProd(){
    
    int a[]={1,2,3,4};
    int b[]={1,2,3,4};

    Vector<int> test2(b,4);
    Vector<int> test1(a,4);
    int test3 = test1 * test2;
    assert(test3 == 30);
}


