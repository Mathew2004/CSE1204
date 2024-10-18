#include<bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;

    while (t--)
    {
        int h,n; 
        cin >> h >> n;
        vector<int> a(n);
        vector<int> c(n);
        vector<pair<int,int>> ac;
        for (int i = 0; i < n; i++){
             cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            cin >> c[i];
        }
        for (int i = 0; i < n; i++){
            ac.push_back({a[i],c[i]});
        }
        
        long long l=1, r=1e12, ans=0;
        while (l <= r) {
            long long mid = (l+r)/2;
            long long damage = 0;

            for(int i=0; i<n; i++){
                long long att = (mid + c[i]-1)/c[i];
                damage += (att * a[i]);
                if(damage >= h) break;
            }
            if(damage >= h) {
                r = mid-1;
                ans = mid;
            }
            else{
                l = mid+1;
            }
            
        }
        cout << ans << endl;
    }
}