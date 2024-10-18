#include<bits/stdc++.h>
 
#define ll long long
#define vec vector
#define pb push_back
#define pop pop_back
#define max(a,b) (a>b)?a:b
 
 
using namespace std;
 
 
void solve(){
    int n;   cin >> n;
    vec<int> a(n);
    // vec<int> b;
 
    for(auto &i:a) cin >> i;
 
    (a[0]==1)?(cout<<"YES\n"):(cout << "NO\n");
 
 
}
 
 
int main(){
    int t; 
    cin >> t;
 
    while(t--){
        solve();
    }
    
   
 
}