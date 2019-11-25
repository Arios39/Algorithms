//
//  arios39.cpp
//  lab04
//
//  Created by Andres Rios on 3/2/19.
//  Copyright © 2019 Andres Rios. All rights reserved.
//Final edit: friday at 2:35pm
// coded using pesudo code and lecture notes
#include <iostream>
using namespace std;
 int heapsize;
 int length;
 void heap(int size){
    heapsize = size;
}
void arrsize(int size){
    length=size-1;
  
}
//defining them here can help me access heapsize or arraylength(this helped fix an error/ confusion in returning wat to wat in heapsort)- inspiration taken from - CSE165
//always (heapsize < arraylength)

void heapify(int A[],int i ){
    int largest;
    int le = 2*i;
    int ri = 2*i+1;
    //taken from lecture notes left and right child
    
    if (le<heapsize&&A[le]>A[i]){
        //(<=) kept giving me wrong execusions, making it < fixed this issue helped by cristian ortiz on this issue
        largest= le;
    }
   else{
       largest =i;
    }
    if(ri<heapsize&&A[ri]>A[largest]){
        largest=ri;
    }
    if(largest!=i){
        swap(A[i],A[largest]);
        //moves largest node up
        heapify(A,largest);
    }
}

void bheap(int A[]){
    for(int i=length/2;i>=0;i--){             //o(log(n)) pesudo says to 1, but it refers to the first elemnt in 0
        //changed at 6:45
        heapify(A,i);
    }
}

void heapsort(int A[]){
    bheap(A);
    for(int i=length;i>=1;i--){   //n
        //change here 6:43
        swap(A[0],A[i]);
        heapsize--;
        heapify(A,0);   //olog(n) Pesudo heapify(A,1) 1 pertaining to the first element
    }
}

int main(){
    int size;

    cin>>size;
    heap(size);
    arrsize(size);
    int A[size];
    for(int i=0; i<size; i++){
        cin>>A[i];
    }
    
    heapsort(A);
    
    for(int i=0; i<size; i++){
        cout<<A[i]<<";";
     }
}

