#pragma once
#include "SegmentedDeque.h"
#include "MyTuple.h"


template <typename T,typename U,typename ... Types>
Sequence<U>& map(const Sequence<T>& seq, U (*func)( T, Types& ...),Types&...tail){
    MutableSegmentedDeque<U>* result = new MutableSegmentedDeque<U>(seq.GetLength());
    for(int i =0;i<seq.GetLength();i++){
        (*result)[i]=(*func)(seq.Get(i),tail...);
    }
    return *result;
    
}

template <typename T,typename ... Types>
Sequence<T>& where(const Sequence<T>& seq, bool (*func)( T ,Types& ...),Types&...tail){
    MutableSegmentedDeque<T>* result = new MutableSegmentedDeque<T>();
    for(int i =0;i<seq.GetLength();i++){
        if((*func)(seq.Get(i), tail...)==true){
            result->Append(seq.Get(i));
        }
    }
    return *result;
}

template <typename T>
T reduce(const Sequence<T>& seq, T (*func)( T, T),T start ){
    for(int i=0;i<seq.GetLength();i++){
        start = (*func)(start,seq.Get(i));
    }
    return start;
}


template <typename T , typename ... Types>
const T& getFirstArg(const T& first , const Types& ... args){
    return first;
} 

template <typename T >
void findMinLengthHelper(int& min,const T& first ){
    if(first.GetLength()<min){
        min = first.GetLength();
    }
}
template <typename T , typename ... Types>
void findMinLengthHelper(int& min , const T& first,const Types& ... args){
    if(first.GetLength()<min){
        min = first.GetLength();
    }
    findMinLengthHelper(min,args...);
}
template <typename ... Types>
int findMinLength(const Types& ... args){
    int seqMinSize = getFirstArg(args...).GetLength();
    findMinLengthHelper(seqMinSize,args...);
    return seqMinSize;
}


                               
template <size_t I=0 , typename ... TypeForTuple,typename ... Types> 
void zipTupleHelper(size_t& counter ,int& index, Tuple_<TypeForTuple...>& inTuple,const Types& ... args){}


template <size_t I=0 ,typename ... TypeForTuple,typename First,typename ... Types> 
void zipTupleHelper(size_t& counter ,int& index, Tuple_<TypeForTuple...>& inTuple,const First& first , const Types& ... args){
    Get<I>(inTuple) = first.Get(index);
    counter++;
    zipTupleHelper<I+1,TypeForTuple...>(counter,index,inTuple,args...);
}
                    // попытаться сделать самостоятельное определение типов
template <typename ... TypeForTuple,typename ... Types> 
MutableSegmentedDeque< Tuple_< TypeForTuple... > >& zip(const Types& ... args ){
    //реализовать поиск меньшего массива
    int seqSize = findMinLength(args...);
    MutableSegmentedDeque< Tuple_<TypeForTuple ... > >* result = new MutableSegmentedDeque< Tuple_<TypeForTuple ... > >(seqSize);
    for(int i =0; i< seqSize;i++){ 
        Tuple_<TypeForTuple...>* buf =  new Tuple_<TypeForTuple...> ;
        size_t counter =0;
        zipTupleHelper<0 , TypeForTuple...>(counter,i,*buf,args...);
        result->Set( *buf, i);
        delete buf;
    }
    return *result;
}



template <size_t I=0,typename First,typename ... TypeForTuple> 
void unzipTupleHelper(size_t& counter,int& length,Tuple_< MutableSegmentedDeque<TypeForTuple>*...>& inTuple,Sequence< Tuple_< TypeForTuple... > >& toUnzip)
{
    MutableSegmentedDeque<First>* buf  = new MutableSegmentedDeque<First>(length);
    Get<I>(inTuple) = buf;
    for(int i =0;i<length ;i++){
        buf->Set(Get<I>(toUnzip[i]),i);
    }
    counter++;

}

template <size_t I=0 ,typename First,typename Second,typename ... Types,typename ... TypeForTuple> 
void unzipTupleHelper(size_t& counter,int& length,Tuple_< MutableSegmentedDeque<TypeForTuple>*...>& inTuple,Sequence< Tuple_< TypeForTuple... > >& toUnzip)
{
    MutableSegmentedDeque<First>* buf  = new MutableSegmentedDeque<First>(length);
    Get<I>(inTuple) = buf;
    for(int i =0;i<length ;i++){
        buf->Set(Get<I>(toUnzip[i]),i);
    }
    counter++;
    unzipTupleHelper<I+1,Second,Types...>(counter,length,inTuple,toUnzip);
}

template <typename ... TypeForTuple> 
Tuple_< MutableSegmentedDeque<TypeForTuple>*...>&  unzip(Sequence< Tuple_< TypeForTuple... > >& toUnzip){
    Tuple_< MutableSegmentedDeque<TypeForTuple>*...>* result = new Tuple_< MutableSegmentedDeque<TypeForTuple>*...>;
    int seqLength = toUnzip.GetLength();
    size_t counter=0;
    unzipTupleHelper<0,TypeForTuple...>(counter,seqLength,*result,toUnzip);
    return *result;
}


