
#include "Sequence.h"
#include "SegmentedDeque.h"



int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    std::cout<<"___"<<std::endl;
    MutableSegmentedDeque<int> deq (a, 10);
    std::cout <<deq.chankCount<<std::endl;
    std::cout <<deq.start<<std::endl;
    std::cout <<deq.end<<std::endl;
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
        deq.PrintDeque();
        deq.PopBack();
        std::cout<<std::endl;
        
    }
    deq.PrintDeque();
    std::cout<<std::endl;
    deq.InsertAt(8,6);
    deq.PrintDeque();
    std::cout<<std::endl;
    deq.InsertAt(99,6);
    deq.PrintDeque();
    std::cout<<"____"<<std::endl;

    int b[] = {1,2,3,4,5};
    int c[] = {6,7,8,9,10};
    MutableSegmentedDeque<int> deq1 (c,5);
    MutableSegmentedDeque<int> deq2 (b,5);
    deq1.PrintDeque();
    std::cout<<std::endl;
    deq2.PrintDeque();
    std::cout<<std::endl;
    auto deq3 = deq1.Concat(deq2);
    deq3->PrintDeque();
    std::cout<<std::endl;

    std::cout<<"___"<<std::endl;

    int d[10] = {1,2,3,4,5,6,7,8,9,10};
    std::cout<<"___"<<std::endl;
    MutableSegmentedDeque<int> deq4 (d, 10);
    deq4.PrintDeque();
    std::cout<<std::endl;
    auto deq5 = deq4.GetSubsequence(3,7);
    deq5->PrintDeque();
    std::cout<<std::endl;

}