#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    set<int> uq;
    vector<long long> v;
    for(int i = 0; i < n; i++){
        long long a; 
        cin >> a;
        uq.insert(a);
    }

    if(uq.size()== 1 || uq.size() == 2) cout << "YES" << endl;
    else if(uq.size()==3){
        for(auto &i: uq) v.push_back(i);
        if(v[0]+v[2]==2*v[1]  ) cout<<"YES"<<endl; 
        else cout<<"NO"<<endl;
    }
    else
        cout << "NO" << endl;
}