#include<iostream>

using namespace std;


void printOdd(int a[],int i,int j){

      if(i==j){
        if(a[i]%2!=0){
            cout<< a[i] << " ";
        }

      }
      else{
        int m = (i+j)/2;
        printOdd(a,i,m);
        printOdd(a,m+1,j);
      }



}

int main(){
     int n;
     cin >> n;
     int a[n];
     for(int i =0;i<n;i++){
        cin >> a[i];
     }

     printOdd(a,0,n-1);

    return 0;


}
