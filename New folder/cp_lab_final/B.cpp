#include<bits/stdc++.h>
 
#define ll long long
#define vec vector
#define pb push_back
#define pop pop_back
#define max(a,b) (a>b)?a:b
 
 
using namespace std;
 
 

 
 
int main(){
    int n; 
    cin >> n;
    
    vec<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 1;

    for(int i=0; i<n; i++){
        if(a[i] >= ans){
            ans++;
        }
    }

    cout << ans << endl;

    
   
 
}

