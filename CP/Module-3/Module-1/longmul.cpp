#include<bits/stdc++.h>
 
#define ll long long
#define vec vector
#define pb push_back
#define pop pop_back
#define max(a,b) (a>b)?a:b
 
using namespace std;

void solve(){
    string x,y; cin >> x;
    cin >> y;
    int flag=0;
    string s1,s2;
    for(int i=0; i<x.size(); i++){
        if(flag==0){
            if(x[i]==y[i]){
                s1 += x[i];
                s2 += x[i];
            }
            else if(x[i] > y[i]){
                flag = 1;
                s1 += x[i];
                s2 += y[i];
            }else{
                flag = 1;
                s1 += y[i];
                s2 += x[i];
            }
        }else{
            if(x[i]>y[i]){
                s1 += y[i];
                s2 += x[i];
            }
            else{
                s1 += x[i];
                s2 += y[i];
            }
        } 
    }
    for(auto &i: s1) cout << i;
    cout  << endl;
    for(auto &i: s2) cout << i;
    cout << endl;
}
 
 
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
 
}