    #include <bits/stdc++.h>
    #define ll long long int
    using namespace std;
    void Lakshyasolve(){
        ll n, m;
        cin >> n >> m;
     
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                ll x1 = i / 2, x2 = j / 2;
                ll y1 = (x1 + x2) & 1, y2 = ((i & 1) + (j & 1)) & 1;
     
                cout << (y1 ^ y2) << " ";
            }
            cout << endl;
        }
    } 
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll T = 1;
        cin >> T;
        while (T--) {
            Lakshyasolve();
        }     
    }