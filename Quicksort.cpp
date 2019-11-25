//
//  main.cpp
//  lab04.5
//
//  Created by Andres Rios on 3/2/19.
//  Copyright © 2019 Andres Rios. All rights reserved.
//final edit Friday: 2:47pm
// coded with pesudo code from book and from lecture(structure for partition and quicksort) notes(randompartition)
#include <iostream>
using namespace std;


int part(int arr[], int p, int r){


    int x = arr[r];
    int i = (p - 1);


    for(int j =p;j<=r-1;j++){
        if(arr[j]<=x){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);

    return (i+1);
}



int randompartition(int arr[],int p,int r){
    //random function help from cplusplus library
    int  random = p+ rand() % (r - p);
    //collaborated with cristian ortiz with coming up with a workable random int
    swap(arr[r],arr[random]);
    return part(arr,p,r);
}







void quicksort(int arr[], int p, int r){
    if (p<r){
      int q = randompartition(arr,p,r);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,r);
    }
}


int main() {
    int size;
  // cout<<endl;
    cin>>size;
    int arr[size];
    for(int i = 0; i<size;i++){
        cin>>arr[i];
    }
    quicksort(arr, 0, size-1);
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<";";
    }
    return 0;
}
