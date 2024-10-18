#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=1; i<n; i++){
        int j=i-1, curr = arr[i];
        while(j>=0 && curr < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }

    for(auto i: arr) cout << i << " ";
    cout << endl;
 

}