#include<iostream>


using namespace std;

int countEven(int arr[],int i, int j){

     if(i==j){
        if(arr[i]%2==0){
            return 1;
        }
        return 0;
     }
     else {
        int mid = (i+j)/2;
        int leftec = countEven(arr,i,mid);
        int rightec = countEven(arr,mid+1,j);

        return leftec + rightec;
     }

}

int main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int ec = countEven(arr,0,n-1);
    cout << ec;

    return 0;

}

