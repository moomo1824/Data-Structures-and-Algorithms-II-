#include<iostream>

using namespace std;

long long power(int b,int p){
    if(p==0){
        return 1;
    }
    if(p==1){
        return b;
    }
    if(p%2==0){
        int hp = power(b,p/2);
        return hp*hp;
    }
    else{
        return b*power(b,p-1);
    }


}


int main(){
    int b, p ;
    cin >>b;
    cin >>p;
    long long result = power(b,p);
    cout << result;
    return 0;

}
