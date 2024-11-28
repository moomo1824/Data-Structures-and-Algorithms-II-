#include <iostream>
using namespace std;


int cal_sum(int a[],int i , int j){

        if(i==j){
            return a[i];
        }
        else{
            int m=(i+j)/2;
            int lsum=0,rsum=0;
            lsum=cal_sum(a,i,m);
            rsum=cal_sum(a,m+1,j);

            return lsum+rsum;

        }



}
int main(){

       int n;
       int sum=0;
       cin >> n;
       int a[n];
       for(int i=0;i<n;i++){
        cin >> a[i];
       }
       sum = cal_sum(a,0,n-1);
       cout << sum;
       return 0;
}

