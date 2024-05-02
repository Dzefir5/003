#include "TestMapReduce.h"
#include "TestMyTuple.h"
#include "SegmentedDequeTest.h"
#include "DynamicArrayTest.h"

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
    Test_SegmentedDeque_Split();
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