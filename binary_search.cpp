#include<iostream>

using namespace std;

int binarySearch(int arr[],int i , int j , int x){

        if(i<=j){
            int mid=(i+j)/2;
            if(x == arr[mid]){
                return mid;

            }
            else if(x<arr[mid]){
                return binarySearch(arr,i,mid-1,x);
            }
            else {
                return binarySearch(arr,mid+1,j,x);
            }

        }
        return -1;

}
int main(){
    int n;
     cin >> n;
     int a[n];
     for(int i =0;i<n;i++){
        cin >> a[i];
     }
     int x;
     cin >>x;
     int result = binarySearch(a,0,n-1,x);
     if(result != -1){
        cout << "The value is found";
     }
     else {
        cout << "not found";
     }

}
