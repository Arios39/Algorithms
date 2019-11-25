//Created by Andres rios

#include <iostream>
using namespace std;

void display(int arr[],int size){
    for (int i=0; i<size+1;i++){
        cout << arr[i] << ";";
        }
    cout<<endl;
}

void insertion_sort(int arr[],int length){

    int j, temp;
    for(int i=1; i<length; i++){
        j=i;
        
        while (j>0 && arr[j-1]>arr[j]){
            temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;

}
//pr++
 display(arr,i);
        
    }
}
int main(){
  //  cout<<endl;
    int length;
    cin >> length;
    int sort[length];
    for (int i=0; i<length; i++){
        cin>>sort[i];
    }
   
   insertion_sort(sort, length);
  //  display(arr,length);

    return 0;
}
