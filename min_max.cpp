#include<iostream>

using namespace std;

struct Res {
   int mx;
   int mn;
};

Res find_max_min(int arr[],int i , int j){
    if(i==j){
        return {arr[i],arr[i]};
    }
    else {
        int m = (i+j)/2;
        Res res1 = find_max_min(arr,i,m);
        Res res2 = find_max_min(arr,m+1,j);

        int mx = max(res1.mx,res2.mx);
        int mn = min(res1.mn,res2.mn);

        return {mx,mn};
    }



}
int main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    Res res = find_max_min(arr,0,n-1);
    cout << res.mx;
    cout << res.mn;


}
