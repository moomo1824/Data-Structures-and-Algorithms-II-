#include<bits/stdc++.h>

using namespace std;


struct Pair{
    int a,b;

};

struct comp_a{
     bool operator()(const Pair& p1 , const Pair& p2){
     return p1.a < p2.a;
     }

};

int main(){
    priority_queue<Pair , vector<Pair> , comp_a> Q;

    int n;
    cin >> n;
    for(int i=0;i<n;++i){
            Pair p;
            cin >> p.a >> p.b;
            Q.push(p);

    }
    while(!Q.empty()){
        Pair p = Q.top();
        Q.pop();

        cout << p.a << p.b;
    }
    return 0;


}
