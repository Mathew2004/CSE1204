#include<bits/stdc++.h>
#define vec vector<int> 
#define ll long long
using namespace std;

 
int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vec c(n);
        for(auto &i:c) cin >> i;

        vector<int> right(n);
        right[0] = 0;
        right[1] = 1;
        for(int i=2; i<n; i++){
            if(c[i]-c[i-1] < c[i-1]-c[i-2]){
                right[i] = right[i-1] + 1;
            }else{
                right[i] = right[i-1] + c[i]-c[i-1];
            }
        }
        vector<int> left(n);
        left[n-1] = 0;
        left[n-2] = 1;
        for(int i=n-3; i>=0; i--){
            if(c[i+1]-c[i] < c[i+2]-c[i+1]){
                left[i] = left[i+1] + 1;
            }else{
                left[i] = left[i+1] + c[i+1]-c[i];
            }
        }
        int m; cin >> m;
        while(m--){
            int x,y; cin >> x >> y;
            x -= 1;
            y -= 1;
            if(x<y) cout << right[y] - right[x] << endl;
            else cout << left[y]-left[x] << endl;

        }
    }
}