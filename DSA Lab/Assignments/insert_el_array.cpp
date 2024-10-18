#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
    int arr[n+1] = {1,2,3,4,5};
    int p,x;
    cin >> p >> x;

    // CHeck the valid possition
    if(p>n || p<0) cout << "Invalid";
    else{
        for(int i=n-1; i>=p-1; i-- ){
            arr[i+1] = arr[i];
        }
        arr[p-1] = x;
    }
    for(auto i:arr) cout << i << endl;
}