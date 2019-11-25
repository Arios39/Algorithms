//  main.cpp
//  lab05
//
//  Created by Andres Rios on 3/14/19.
//  Copyright © 2019 Andres Rios. All rights reserved.
//Last edited at 10:24 am
#include <iostream>
#include<deque>
using namespace std;
static int size;

//counting sort pesudo code
//assisted by daniel toriz
//collabed cristian ortiz
//help understanding radix sort from mark at pals
void countingsort(deque<int> A[], deque<int> B[],int pos){
    int C[4];
    //largest number of k can only be 3, therefore we need a size 4
    //fixes issue with not not making array big enough
    
    for (int i=0; i < 4; i++){
        C[i]=0;
    }
    for (int j=0; j< size; j++){
        C[A[j][pos]]=C[A[j][pos]]+1;
    }
    for (int i=1; i < 4; i++){
        C[i]=C[i]+C[i-1];
    }
    
    for (int j = size-1; j>=0; j--){
        //size-1 helped fixed issue
        B[C[A[j][pos]] - 1] = A[j];
        C[A[j][pos]]=C[A[j][pos]]-1;
        }
    
}
/*int getd(int k){
    int d;
    //with base being 10
    d = 10%k;
    return d;
}*/
void radixsort(deque<int> A[], deque<int> B[]){
    for(int pos = 9; pos>=0;pos--){
        countingsort(A, B ,pos);

        for(int i=0;i<size;i++){
            A[i]=B[i];
        }
    
    }
    //pos is 9 for the amount of colums starting at 0-9
    //copy to the output array

    
}


int main(int argc, const char * argv[]) {
    
    int k;
    //   cout<<endl;
    cin>>size;
    //deque<deque<int>>A;
    deque<int>A[size];
    deque<int>B[size];
    for(int i=0; i<size; i++){
      //  deque<int>temp;
        for(int j=0; j<10;j++){
            cin>>k;
            A[i].push_back(k);
            //temp.push_back(k);
        }
    }
    radixsort(A,B);
    for(int i=0; i<size; i++){
         for(int j=0; j<10;j++){
            cout<<B[i][j]<<";";
        }
        cout<<endl;
    }
 
    
}
