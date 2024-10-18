#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n+1];
    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=1; i<n; i++){
        int j = i-1, curr = arr[i];
        while(j>=0 && arr[j]>curr){
            arr[j+1] = arr[j];
            j--;
        }
        //  5 2 3 50 5
        //  2 5 3 50 5
        //  2 3 5 50 5
        //  2 3 5 50 5
        //  2 3 5 5 50

        arr[j+1] = curr;
    }

    for(int i=0; i<n; i++) cout << arr[i] << ' ' ;
    cout << endl;
}