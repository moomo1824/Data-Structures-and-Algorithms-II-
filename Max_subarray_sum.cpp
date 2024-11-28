#include<iostream>

using namespace std;
int subarray_crossing_sum(int a[],int l,int m , int h){
    int left_sum=INT_MIN;
    int sum=0;
    for(int i=m;i>=l;i++){
        sum+=a[i];
        if(sum>left_sum){
            left_sum=sum;
        }
    }
    int right_sum=INT_MIN;
    sum=0;
    for(int i=m;i>=h;i++){
        sum+=a[i];
        if(sum>right_sum){
            right_sum=sum;
        }
    }
    return left_sum+right_sum;

}

int max_subarray_sum(int a[],int i , int j){
    if(i==j){
        return a[i];
    }
    else{
        int mid = (i+j)/2;
        return max({max_subarray_sum(a,i,mid),
                    max_subarray_sum(a,mid+1,j),
                    subarray_crossing_sum(a,i,mid,j)});
    }

}
int main(){
     int n;
     cin >> n;
     int a[n];
     for(int i =0;i<n;i++){
        cin >> a[i];
     }
     int res = max_subarray_sum(a,o,n-1);
     cout << res;
}
