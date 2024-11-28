#include<iostream>

using namespace std;

void swap(int *a,int *b){
    int t = *a;
    *a=*b;
    *b=t;
}

int partition(int arr[],int low , int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<=high;i++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    swap(arr[i+1],arr[high]);
    return  (i+1);
    }

}
void quickSort(int arr[],int low , int high){
    if(low < high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }

}
int main(){
    int n;
     cin >> n;
     int a[n];
     for(int i =0;i<n;i++){
        cin >> a[i];
     }
     for(int i =0;i<n;i++){
        cout << a[i];
     }
     quickSort(a,0,n-1);
     cout << " ";
     for(int i =0;i<n;i++){
        cout << a[i];
     }



}
