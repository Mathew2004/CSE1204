#include <bits/stdc++.h>
#define ll long long

 
using namespace std;
 
ll Imbalance(int n, vecll& a) {
    vector<int> left_max(n), right_max(n), left_min(n), right_min(n);
    stack<int> st;
    
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] < a[i]) st.pop();
        left_max[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        right_max[i] = st.empty() ? n - 1 : st.top() - 1;
        st.push(i);
    }
    
    while (!st.empty()) st.pop();
    
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] > a[i]) st.pop();
        left_min[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }
    
    while (!st.empty()) st.pop();
    
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        right_min[i] = st.empty() ? n - 1 : st.top() - 1;
        st.push(i);
    }

    ll total_imbalance = 0;
    
    for (int i = 0; i < n; ++i) {
        ll max_contrib = (ll)(i - left_max[i] + 1) * (right_max[i] - i + 1);
        ll min_contrib = (ll)(i - left_min[i] + 1) * (right_min[i] - i + 1);
        total_imbalance += a[i] * (max_contrib - min_contrib);
    }
    
    return total_imbalance;
}
 
int main() {
    int n;
    cin >> n;
    
    vecll a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    cout << Imbalance(n, a) << endl;
    
    return 0;
}