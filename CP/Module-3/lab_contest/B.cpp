#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>> power;

int main(){
    int t; cin >> t;
    while(t--){
        int n,q; cin >> n >> q;
        vector<long long> a(n);
        vector<int> x(q);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<q; i++){
            cin >> x[i];
        }
        set <long long>uq; 
        for(int i=0; i<q; i++){
            if(uq.count(x[i])) continue;
            uq.insert(x[i]);
            for(int j=0; j<n; j++){
                if(a[j]% (1<<(x[i]))  == 0){
                    a[j] += (1<<(x[i]-1));
                }
            }
        }

        for(auto &i: a) cout << i << " ";
        cout << endl;

    }
}