//
//  main.cpp
//  lab06
//
//  Created by Andres Rios on 3/15/19.
//  Copyright © 2019 Andres Rios. All rights reserved.
#include <iostream>
#include<list>
using namespace std;
//collaborated with cristian ortiz
int m;
//array of lists
void hashinsertion(list<int>T[],int k){
    int j=k%m;
    bool space=false;
  //taken from lecture notes
   if(m!=0){
    T[j].push_front(k);
       space=true;
    }
   if(!space){
      cout<<"Hash Table Overflow";
    }
}
void hashsearch(list<int>T[], int k){
    // help with iterators from https://en.cppreference.com/w/cpp/container/list
    list <int> :: iterator it;
    int i=0;
    bool found=false;
    int j=k%m;
   // for(int i =0; i<m;i++){
    for(it = T[j].begin(); it != T[j].end(); ++it){
        //advance(it,j);
        if(*it==k){
            cout<<k<<":FOUND_AT"<<j<<","<< i<<";"<<endl;
            found=true;
        }
  i++;
    }
    if(!found){
        cout<<k<<":NOT_FOUND;"<<endl;
    }
    
}
void hashdelete(list<int>T[],int k){
    list <int> :: iterator it;
    int i=0;
    bool deleted=false;
    int j=k%m;
    for(it = T[j].begin(); it != T[j].end(); ++it){
        //advance(it,j);
        if(*it==k){
            T[i].erase(it);
            cout<<k<< ":DELETED;"<<endl;
            deleted=true;
            break;
            //break loop to help from deleting more than one if there are repeating numbers
        }
        i++;
    }
  
    if(!deleted){
        cout<<k<<":DELETE_FAILED;"<<endl;
    }
}
void printtable(list<int>T[]){
    //help with iterators from https://en.cppreference.com/w/cpp/container/list
    list <int> :: iterator it;
    for(int i = 0; i<m;i++){
        cout<<i<<":";
        for(it = T[i].begin(); it != T[i].end(); ++it){
            cout<<*it<<"->";
        }
        cout<<";"<<endl;
    }
    
    
}

int main(int argc, const char * argv[]) {
    //collaborated with cristian ortiz for while loop
    cin>>m;
    char func;
    int k;
    list<int>T[m];
    while(m!=0){
        cin>>func;
        if(func=='i'){
            cin>>k;
            hashinsertion(T, k);
        }
        if(func=='s'){
            cin>>k;
            hashsearch(T, k);
        }
        if (func=='o'){
            printtable(T);
        }
        if (func=='d'){
            cin>>k;
            hashdelete(T, k);
        }
        if(func=='e'){
            break;
        }
        
        
    }

    return 0;
}
