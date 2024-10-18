#include <bits/stdc++.h>
#define ll long long ;
using namespace std;

const int N = 5e5 + 50;
int check, t, val;
long long sum, maxi, l, arr[N];
int main(){
  cin >> t;
  while (t--){
    cin >> check;
    if (check == 1){
      cin >> arr[++val];
      sum += (arr[val] - maxi);
      maxi = arr[val];
      while (l < val && arr[l + 1] * (l + 1) < sum)
        sum += arr[++l];
    }
    else
      printf("%.10lf\n", maxi - double(sum) / double(l + 1));
  }
  return 0;
}