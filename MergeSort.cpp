//
//  main.cpp
//  Lab02
//
//  Created by Andres Rios on 2/1/19.
//  Copyright © 2019 Andres Rios. All rights reserved.
//
#include <iostream>
using namespace std;
/* testing if mid is correct
 void print(int arr[],int p,int q){
    cout<<q<<";"<<endl;
}
 */
void merge(int arr[], int low, int mid, int high){
    //a=n1
    int a = mid-low+1,i,j,k;
    int b = high-mid;
    int L[a];
    int R[b];

    for (int i=0; i<a; i++ ){
        //i = low;
        L[i]=arr[low+i]; //moves first half of values to l[]
    }
    for (int j =0; j<b; j++ ){
        R[j]=arr[mid+j+1]; //moves next half value into r[]
    }
    i=0;j=0;
    for (k = low;i<a&&j<b; k++ ){
        if(L[i]<R[j]){
            arr[k] = L[i++];
        }
        else{
            arr[k]=R[j++];
            
        }
    }
    while(i<a){// merges left  array back
        arr[k++]=L[i++];
    }
    while (j<b){// merges right back
        arr[k++]=R[j++];

    }
    
}

void merge_sort(int arr[],int low,int high){
      int mid;

    if(low < high){
      
        mid = (low + high)/2;//looks for middle index
       merge_sort(arr,low,mid);//breaks up array to the left(left sub array)
     merge_sort(arr,mid+1,high);// breaks array to the right(right sub array)
      merge(arr,low,mid,high);
        
    }

}


int main() {
    int length;

    cin >> length;
    int arr[length];
   
    for (int i=0; i<length; i++){
        cin>>arr[i];
}
    
    merge_sort(arr,0,length-1);

   for(int i=0;i<length;i++)
  {
cout << arr[i] << ";";
        
   }
    
}

