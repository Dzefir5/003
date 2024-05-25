#include "TestMapReduce.h"
#include "TestMyTuple.h"
#include "SegmentedDequeTest.h"
#include "DynamicArrayTest.h"
#include "StackTest.h"
#include "QueueTest.h"
#include "VectorTest.h"

void Test_DynamicArray(){
    Test_DynamicArray_CompareOperator();
    Test_DynamicArray_Set();
    Test_DynamicArray_Constructors();
}


void Test_SegmentedDeque(){
    Test_SegmentedDeque_Constuctors();
    Test_SegmentedDeque_Append();
    Test_SegmentedDeque_RemoveAt();
    Test_SegmentedDeque_Prepend();
    Test_SegmentedDeque_InsertAt();
    //Test_SegmentedDeque_Split();
    Test_SegmentedDeque_Slice();
    Test_SegmentedDeque_CompareOperator();
    Test_SegmentedDeque_AccessOperator();
    Test_SegmentedDeque_Concat();
    Test_SegmentedDeque_SubSequence();
}

void Test_MapReduce(){
    Test_MyTuple();
    Test_Map();
    Test_Where();
    Test_Reduce();
    Test_ZipUnzip();
}
void Test_Stack(){
    Test_Stack_Concat();
    Test_Stack_Constuctors();
    Test_Stack_Push();
    Test_Stack_Pop();
    Test_Stack_SubStack();
}
void Test_Queue(){
    Test_Queue_Concat();
    Test_Queue_Constuctors();
    Test_Queue_Push();
    Test_Queue_Pop();
    Test_Queue_SubQueue();
}
void Test_Vector(){
    Test_Vector_Constuctors();
    Test_Vector_Sum();
    Test_Vector_Mult();
    Test_Vector_ScalProd();
}