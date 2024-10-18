#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int ang; cin >> ang;

        for(int i=3; i<= 1000; i++){
            if((i*ang)%180 == 0){
                int res = (i*ang)/180;
                if(res>=1 && res<=i-2){
                    cout << i << endl;
                    break;
                }
            }
        }
    }
}