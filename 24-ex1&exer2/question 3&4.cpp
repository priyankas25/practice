#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
#include <sstream>
using namespace std;

int main(){
   int arr[6],arr1[6],k=0;
   for(int i=0;i<5;i++){
    cin>>arr[i];
   }

   unordered_set<int>s;
   for(int j=0;j<5;j++){

        if(sizeof(arr)/sizeof(arr[0])==1){
            arr1[0] = arr[0];
            break;
        }

        if(s.find(arr[j])!=s.end()){
            arr1[k] = arr[j];
            k++;
        }
        else{
            s.insert(arr[j]);
        }
   }

   for(int i=0;i<5;i++){
    cout<<arr1[i];
   }

    return 0;
}
