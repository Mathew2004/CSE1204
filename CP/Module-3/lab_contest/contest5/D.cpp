#include<bits/stdc++.h>
#define vecll vector<long long> 
#define ll long long

using namespace std;

int SOD(int a){
    int sum = 0;
    while(a){
        sum += a%10;
        a/=10;
    }
    return sum;
}

vecll preSum(200005);



int main(){
    preSum[0] = 0;
    for(int i=1; i<200005; i++){
        preSum[i] = preSum[i-1] + SOD(i);
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << preSum[n] << endl;
    }
}