#include<bits/stdc++.h>

using namespace std;


struct Fish{

    string name;
    int price;

    Fish(string n,int p ): name(n),price(p){}

};

struct priceCompare{
    bool operator()(const Fish& f1 , const Fish& f2){
        return f1.price >f2. price;

     }
};

int calculatePrice(const string& name){
    int sum=0;
    for(char c : name){
        sum+=(int)c;
    }
    return sum;

}

int main(){

   priority_queue<Fish , vector<Fish>,priceCompare> pq;
   vector <Fish> fishes;
   int n;
   cin >>n;
   for(int i=0;i<n;++i){
    string fishname;
    cin >> fishname;

    int price = calculatePrice(fishname);
    Fish fish(fishname,price);
    pq.push(fish);
    fishes.push_back(fish);
   }

   cout << "Fish sorted according to price";
   while(!pq.empty()){
    Fish f = pq.top();
    pq.pop();
    cout<<f.name << "----> price" <<f.price << "\n";
   }

   auto maxfish =max_element(fishes.begin(),fishes.end(),[](const Fish& f1,const Fish& f2){
            return f1.price < f2.price;

   });
   cout << maxfish->name;






}
//////////////////
#include <iostream>
#include <vector>

using namespace std;

// Merge function used in merge sort
int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    int inversions = 0;

    // Merge the two halves
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            inversions += (leftArr.size() - i); // Count inversions
        }
    }

    // Copy the remaining elements of leftArr, if any
    while (i < leftArr.size()) {
        arr[k++] = leftArr[i++];
    }

    // Copy the remaining elements of rightArr, if any
    while (j < rightArr.size()) {
        arr[k++] = rightArr[j++];
    }

    return inversions;
}

// Recursive function to count inversions using merge sort
int mergeSortAndCount(vector<int>& arr, int left, int right) {
    int inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Count inversions in the left half
        inversions += mergeSortAndCount(arr, left, mid);

        // Count inversions in the right half
        inversions += mergeSortAndCount(arr, mid + 1, right);

        // Count split inversions
        inversions += mergeAndCount(arr, left, mid, right);
    }
    return inversions;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int inversionCount = mergeSortAndCount(arr, 0, n - 1);

    cout << "Number of inversions: " << inversionCount << endl;

    return 0;
}

