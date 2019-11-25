//
//  main.cpp
//  Lab07
//
//  Created by Andres Rios on 3/27/19.
//  Copyright © 2019 Andres Rios. All rights reserved.
//
//help with pesudo code from hector alfaro
//bottom cut and print pesudo code used from book
#include <iostream>
using namespace std;
int q;


int bottomupcutrod(int p[],int n){
    int r[n+1];
    int s[n+1];
    int x=n;
    r[0]=0;
    for(int j=1;j<=n;j++ ){
        q=0;
        for(int i =1;i<=j;i++){
            if(q<p[i]+r[j-i]){
                q=p[i]+r[j-i];
                s[j]=i;
            }
        }
           r[j]=q;
    }
    cout<<r[n]<<endl;
    while (x>0){
        cout<<s[x]<<" ";
        x= x-s[x];
    }
      return -1;

}


/*int cutrod(int p[],int n){
    if (n==0){
        return 0;
    }
    int q =0;
    for(int i=1;i<=n;i++){
        q = max(q,p[i]+cutrod(p,(n-i)));
    }
    
    return q;
}
*/


int main(int argc, const char * argv[]) {
    int length;
    cin>>length;
    int p[length+1];
    p[0]=0;
    for(int i=1; i<length+1;i++){
        cin>>p[i];
    }
    
  cout<<bottomupcutrod(p, length)<<endl;
    return 0;
}
