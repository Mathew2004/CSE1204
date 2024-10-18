#include<bits/stdc++.h>
#define vec vector<int> 
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()


using namespace std;

ll calculate_contribution(vector<int>& pos) {
    sort(pos.begin(), pos.end());  // Sort pos
    ll total = 0;
    ll prefix_sum = 0;
    
    for (int i = 0; i < pos.size(); ++i) {
        total += (ll)pos[i] * i - prefix_sum;  
        prefix_sum += pos[i];  
    }
    
    return total;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Table input
    vector<vector<int>> table(n, vector<int>(m));
    
    // Map to store pos for each color
    unordered_map<int, vector<pair<int, int>>> color_pos;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> table[i][j];
            color_pos[table[i][j]].emplace_back(i, j); 
        }
    }
    
    ll total_distance = 0;
    
    // Process each color
    for (auto& entry : color_pos) {
        vector<int> rows, cols;
        
        for (auto& pos : entry.second) {
            rows.push_back(pos.first);
            cols.push_back(pos.second);
        }
        
        total_distance += calculate_contribution(rows);
        total_distance += calculate_contribution(cols);
    }
    
    cout << total_distance << endl;

    return 0;
}
