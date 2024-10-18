#include<bits/stdc++.h>
 
#define ll long long
#define vec vector
#define pb push_back
#define pop pop_back
#define max(a,b) (a>b)?a:b
#define N 100010
 
using namespace std;
 


ll a[N], b[N];
ll price(ll k,ll n){
	for (ll i = 1; i <= n; i++)
		b[i-1] = a[i] + (i*k);
	sort(b, b + n);

	ll p = 0;
	for (ll i = 0; i < k; i++)
		p += b[i];

	return p;
}

int main(){
	ll i, j, k;
	ll n, m;

	cin >> n >> m;
	for (i = 1; i <= n; i++)
		cin >> a[i];

	ll high, low, mid, ans, cost;
	high = n, low = 0, ans = 0, cost = 0;

	while (high>=low){
		mid = (low + high) / 2;

		//Cost
		k = price(mid, n);
		//cout << k <<" "<<mid<<" "<<a[mid]<< endl;
		if (k == m){
			cout << mid <<" "<<m<< endl;
			return 0;  
		}

		if (k > m)
			high = mid - 1;
		else
			low = mid + 1, ans = mid, cost=k;
	}

	cout << ans << " " << cost << endl;

	return 0;
}