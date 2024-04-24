

#include "Sequence.h"
#include "DynamicArray.h"
#include <iostream>

struct OpStat
{
    int AppendCount =10;
    int PrependCount =10;
    int InsertCount = 10; 

    void ScaleParameters(int scale){
        AppendCount = AppendCount/scale;
        PrependCount = PrependCount/scale;
        InsertCount  = InsertCount /scale;
    }
    int ParametersSum(){
        return AppendCount + PrependCount + InsertCount;
    }
};

template <typename T>
class Deque : Sequence<T> {
private:
    DynamicArray<T>* data = nullptr;
    int maxBuffer = 1024;
    int capacity=0;
    int size=0;
    int start=0;
    int end=0;
    OpStat stat ;

    void Reserve(int newCapacity){
        int offset = 0; 
        double offsetEps = static_cast<double>(stat.PrependCount) / static_cast<double>(stat.ParametersSum()) ;
        offset = (newCapacity - size) * offsetEps;
        data->Resize(newCapacity,offset);
        start = offset;
        end = size + start - 1 ;
        stat.ScaleParameters(10);
        capacity = newCapacity;
    }

public:

    Deque():size(0),capacity(2),start(0),end(0){
        data = new DynamicArray(capacity);
    }
    Degue(int inSize):size(inSize){
        capacity = inSize*2 > inSize+maxBuffer ? inSize+maxBuffer :  inSize*2;
        data = new DynamicArray(capacity);
        start = (capacity - size)/2;
        end = start+size-1;
    }   
    Degue(const T& fillElem , int inSize):Degue(inSize){
        for(int i =0;i<inSize;i++){
            data->Set(fillElem,i+start);
        }
    }
    Degue(T* items, int inSize):Degue(inSize){
        for(int i =0;i<inSize;i++){
            data->Set(items[i],i+start);
        }
    }
    Degue(const Sequence<T>& seq):Degue(seq.GetLength()){
        for(int i =0;i<seq.GetLength();i++){
            data->Set(seq.Get(i),i+start);
        }
    }
    T Get(int index){
        if(index>=size){}
        return data->Get(index+start);
    }
    T GetFirst(){
        return data->Get(start);
    }
    T GetLast(){
        return data->Get(end);
    }
    int GetLength(){
        return size;
    }

    Deque<T>* Append (const T& item){
        if(end+1==capacity){
            Reserve(size*2 > size+maxBuffer ? size+maxBuffer :  size*2);
        }
        end++;
        data->Set(item,end);
        return this;
    }
    Degue<T>* Prepend(const T& item){
        if(start==0){
            Reserve(size*2 > size+maxBuffer ? size+maxBuffer :  size*2);
        }
        start--;
        data->Set(item,start);
        return this;
    }
    Degue<t>* InsertAt(const T& item , int index){
        
        return this;
    }
    T& operator[](int index){
        if(index>=size){}
        return (*data)[index+start];
    }


};