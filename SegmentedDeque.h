#pragma once

#include "Sequence.h"
#include "DynamicArray.h"
#include <iostream>


template <typename T>
class SegmentedDeque : public Sequence<T> {
public:
    DynamicArray<T*>* data = nullptr;
    int chankSize = 4;
    int chankCount = 0;
    int size=0;
    int start=0;
    int end =0;

    void swap(SegmentedDeque<T>& toSwap){
        MySwap( data,toSwap.data);
        MySwap(chankCount,toSwap.chankCount);
        MySwap( size,toSwap.size);
        MySwap(start,toSwap.start);
        MySwap(end,toSwap.end);
    }
    
protected:

    virtual SegmentedDeque<T>* Instance() = 0;
    virtual const SegmentedDeque<T>* Instance() const = 0;
    
public:

    SegmentedDeque(){
        data = new DynamicArray<T*>(1);
        (*data)[0] = new T[chankSize];
        chankCount =1 ;
        size = 0;
        start = chankSize/2;
        end = (chankSize/2)-1;
    }
    SegmentedDeque(int inSize):size(inSize){
        int startOffset = ( inSize % chankSize )/2;
        chankCount = inSize/chankSize + 1;
        data = new DynamicArray<T*>(chankCount);
        for(int i =0 ;i<chankCount ; i++){
            (*data)[i] = new T[chankSize];
        }
        if(chankCount ==1){
            start = (chankSize - inSize)/2;
            end = start + inSize - 1;
        }
        if(chankCount ==2){
            startOffset = inSize/2;
            start = chankSize - startOffset ;
            end = inSize - startOffset - 1 ;
        }
        if(chankCount >= 3){
            startOffset  = (inSize - (chankCount-2)*chankSize)/2;
            start = chankSize - startOffset ;
            end = inSize - (chankCount-2)*chankSize - startOffset -1 ;
        }
    }   
    SegmentedDeque(const T& fillElem , int inSize):SegmentedDeque(inSize){
        for(int i =0;i<inSize;i++){
            (*this)[i] = fillElem;
        }
    }   
    SegmentedDeque(T* items, int inSize):SegmentedDeque(inSize){
        for(int i =0;i<inSize;i++){
            //this->Set(items[i],i);
            (*this)[i] = items[i];
        }
    }
    SegmentedDeque(const Sequence<T>& seq):SegmentedDeque(seq.GetLength()){
        for(int i =0;i<seq.GetLength();i++){
            this->Set(seq.Get(i),i+start);
        }
    }
    SegmentedDeque(const SegmentedDeque<T>& deq):SegmentedDeque(deq.GetLength()){
        for(int i =0;i<deq.GetLength();i++){
            this->Set(deq.Get(i),i+start);
        }
    }


    T Get(int index)  const override{
        if(index<0||index>=size) 
            throw std::out_of_range("invalid index");
        if(index < chankSize - start){
            return (*data)[0][index+start] ;
        }
        if(index>= size - end - 1 ){
            return (*data)[chankCount-1][index - (chankSize - start) - (chankCount -2)*chankSize] ; 
        }
        int chankIndex = ( index - ( chankSize - start )  )/ chankSize + 1 ;
        return (*data)[ chankIndex  ][ ( index - (chankSize - start) ) % chankSize] ; 
    }
    T GetFirst() const override {
        if(size==0) 
            throw std::out_of_range("invalid index");
        return (*data)[0][start];
    }
    T GetLast() const override {
        if(size==0) 
            throw std::out_of_range("invalid index");
        return (*data)[chankCount-1][end];
    }
    SegmentedDeque<T>* Set (const T& item , int index) override {
        SegmentedDeque<T>* result = Instance();
        if(index<0||index>=result->size) 
            throw std::out_of_range("invalid index");
        if(index < result->chankSize - result->start){
            (*(result->data))[0][index+ result->start] = item ; 
            return result;
        }
        if(index>= result->size - result->end - 1 ){
            (*(result->data))[result->chankCount-1][index - (result->chankSize - result->start) - (result->chankCount -2)*result->chankSize] = item ; 
            return result ; 
        }
        
        int chankIndex = ( index - ( result->chankSize - result->start )  )/ result->chankSize + 1 ;
        (*(result->data))[ chankIndex  ][ ( index - (result->chankSize - result->start) ) % result->chankSize] = item ;
        return result ; 
    }
    int GetLength() const override{
        return size;
    }

    SegmentedDeque<T>* Append (const T& item) override {
        SegmentedDeque<T>* result = Instance();
        if(result->end < chankSize - 1){
            result->end++;
            result->size++;
            (*(result->data))[result->chankCount-1][result->end]=item;
        }else{
            (result->data)->Resize(chankCount+1);
            (*(result->data))[result->chankCount]= new T[chankSize];
            result->end=0;
            result->chankCount++;
            result->size++;
            (*(result->data))[result->chankCount-1][result->end]=item;
        }

        return result;
    }
    SegmentedDeque<T>* Prepend(const T& item) override {
        SegmentedDeque<T>* result = Instance();
        if(result->start > 0 ){
            result->start--;
            result->size++;
            (*(result->data))[0][result->start]=item;
        }else{
            result->data->Resize(result->chankCount+1,1);
            (*(result->data))[0]= new T[chankSize];
            result->start = chankSize-1;
            result->chankCount++;
            result->size++;
            (*(result->data))[0][result->start]=item;
        }

        return result;
    }

    SegmentedDeque<T>* PopFront()  {
        SegmentedDeque<T>* result = Instance();
        if(result->size<0) 
            throw std::invalid_argument("invalid argument in popfront");
        result->size--;
        if (start==chankSize-1){
            result->data->Resize(result->data->GetLength()-1,-1);
            result->chankCount--;
            result->start = 0;
            return result;
        }
        result->start++;
        return result;
    }
    SegmentedDeque<T>* PopBack()  {
        SegmentedDeque<T>* result = Instance();
        if(result->size<0) 
            throw std::invalid_argument("invalid argument in popback");
        result->size--;
        if (result->end==0){
            std::cout<<"call resize"<<std::endl;
            result->data->Resize(result->data->GetLength()-1,0);
            result->chankCount--;
            result->end = chankSize-1;
            return result;
        }
        result->end--;
        return result;
    }

    SegmentedDeque<T>* RemoveAt(int index) override {
        SegmentedDeque<T>* result = Instance();
        if(index == 0){
            result->PopFront();
            return result;
        }
        if(index == size-1){
            result->PopBack();
            return result;
        }
        for(int i = index ; i<result->size-1;i++){
            (*result)[i]=(*result)[i+1];
        }
        result->PopBack();
        /*
        SegmentedDeque<T>* res = new SegmentedDeque<T>();
        for(int i =0;i<index;i++){
            res->Append(result->Get(i));
        }
        for(int i =index+1;i<result->GetLength();i++){
            res->Append(result->Get(i));
        }
        result->swap(*res);
        delete res;
        */

        return result;
    }
    SegmentedDeque<T>* InsertAt(const T& item , int index) override {
        SegmentedDeque<T>* result = Instance();
        if(index == 0){
            result->Prepend(item);
            return result;
        }
        if(index == size){
            result->Append(item);
            return result;
        }
        result->Append(item);
        for(int i = result->size-1 ; i>index;i--){
            (*result)[i]=(*result)[i-1];
        }
        (*result)[index] = item;
        

        /*
        SegmentedDeque<T>* res = new SegmentedDeque<T>();
        for(int i =0;i<index;i++){
            res->Append(result->Get(i));
            std::cout<<"get:"<<result->Get(i) <<std::endl;
        }
        res->Append(item);
        for(int i =index;i<result->GetLength();i++){
            res->Append(result->Get(i));
        }
        result->swap(*res);
        delete res;
        */

        return result;
    }


    void PrintDeque() const {
        if(chankCount ==1){
            for(int i = start ; i<=end; i ++){
                if(i<start||i>end){
                    std::cout<<"-"<<" ";
                }else{
                    std::cout<<(*data)[0][i]<<" ";
                }
            }
            return;
        }
        for(int i = 0 ; i<chankSize; i ++){
            if(i<start){
                std::cout<<"-"<<" ";
            }else{
                std::cout<<(*data)[0][i]<<" ";
            }
        }
        std::cout<<std::endl;
        for(int i  = 0 ; i<chankCount-2;i++){
            for(int j = 0 ;j<chankSize;j++){
                std::cout<<(*data)[i+1][j]<<" ";
            }
            std::cout<<std::endl;
        }
        for(int i = 0 ; i<chankSize; i ++){
            if(i>end){
                std::cout<<"-"<<" ";
            }else{
                std::cout<<(*data)[chankCount-1][i]<<" ";
            }
        }
        std::cout<<std::endl;
        std::cout<<"size : "<<size<< " chanks : "<<chankCount<<std::endl;
        std::cout<<"start index : "<<start<< " end index : "<<end<<std::endl;
        return;
    }


    T& operator[](int index) override {
        if(index<0||index>=size) 
            throw std::out_of_range("invalid index");
        if(index < chankSize - start){
            return (*data)[0][index+start] ;
        }
        if(index>= size - end - 1 ){
            return (*data)[chankCount-1][index - (chankSize - start) - (chankCount -2)*chankSize] ; 
        }
        int chankIndex = ( index - ( chankSize - start )  )/ chankSize + 1 ;
        return (*data)[ chankIndex  ][ ( index - (chankSize - start) ) % chankSize] ; 
    }

    virtual ~SegmentedDeque(){
        for(int i =0 ;i<data->GetLength();i++){
            delete[] data->Get(i);
        }
        delete data;
    }
};



template <typename T>
class MutableSegmentedDeque : public SegmentedDeque<T> {
private:
    SegmentedDeque<T>* Instance() override {
        return static_cast< SegmentedDeque<T>* >(this);
    }
    
    const SegmentedDeque<T>* Instance() const  override {
        return static_cast<const SegmentedDeque<T>*>(this);
    }

public:
    using SegmentedDeque<T>::SegmentedDeque;

    MutableSegmentedDeque<T>* Concat( const Sequence <T>& seq) const override {
        MutableSegmentedDeque<T>* result = new MutableSegmentedDeque<T>(this->GetLength() + seq.GetLength());
        for(int i=0;i<this->GetLength();i++){
            result->Set(this->Get(i),i);
        }
        for(int i=0;i<seq.GetLength();i++){
            result->Set(seq.Get(i),i+this->GetLength());
        }
        return result;
    } 
    MutableSegmentedDeque<T>*  GetSubsequence(int startIndex, int endIndex) const override{
        if(startIndex<0||endIndex<startIndex) throw std::invalid_argument("");
        if(endIndex>=this->size) throw std::out_of_range("");
        MutableSegmentedDeque<T>* result = new MutableSegmentedDeque<T>(endIndex - startIndex + 1);
        for(int i = 0 ; i < endIndex-startIndex +1;i++){
            result->Set(this->Get(startIndex+i),i);
        }
        return result;
    }
};

template <typename T>
class ImmutableSegmentedDeque : public SegmentedDeque<T> {
private:
    ImmutableSegmentedDeque<T>* Clone(){
        return new ImmutableSegmentedDeque<T>(*this);
    }
    SegmentedDeque<T>* Instance() override {
        return static_cast< SegmentedDeque<T>* >( Clone() );
    }
    
    const SegmentedDeque<T>* Instance() const  override {
        return static_cast<const SegmentedDeque<T>*>( Clone() );
    }

public:
    using SegmentedDeque<T>::SegmentedDeque;

    ImmutableSegmentedDeque<T>* Concat( const Sequence <T>& seq) const override {
        MutableSegmentedDeque<T>* result = new MutableSegmentedDeque<T>(this->GetLength() + seq.GetLength());
        for(int i=0;i<this->GetLength();i++){
            result->Set(this->Get(i),i);
        }
        for(int i=0;i<seq.GetLength();i++){
            result->Set(seq.Get(i),i+this->GetLength());
        }
        ImmutableSegmentedDeque<T>* res = new ImmutableSegmentedDeque<T>(*result);
        delete result;
        return res;
    } 
    ImmutableSegmentedDeque<T>*  GetSubsequence(int startIndex, int endIndex) const override{
        if(startIndex<0||endIndex<startIndex) throw std::invalid_argument("");
        if(endIndex>=this->size) throw std::out_of_range("");
        MutableSegmentedDeque<T>* result = new MutableSegmentedDeque<T>(endIndex - startIndex + 1);
        for(int i = 0 ; i < endIndex-startIndex +1;i++){
            result->Set(this->Get(startIndex+i),i);
        }
        ImmutableSegmentedDeque<T>* res = new ImmutableSegmentedDeque<T>(*result);
        delete result;
        return res;
    }
};