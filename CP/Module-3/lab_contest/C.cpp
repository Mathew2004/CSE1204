#include <bits/stdc++.h>
using namespace std;
#define int long long
#define push push_back
#define first_val first
#define second_val second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int test_cases;
    cin >> test_cases;
    
    while(test_cases--){
        int size;
        cin >> size;
        
        vector<vi> values(3, vector<int>(size + 1));
        vector<vi> prefix_sums(3, vector<int>(size + 1));

        // Read the values and compute prefix sums
        for(int row = 0; row < 3; row++){
            for(int col = 1; col <= size; col++){
                cin >> values[row][col];
                prefix_sums[row][col] = prefix_sums[row][col - 1] + values[row][col];
            }
        }

        bool solution_paisi = false;
        vi permutation = {0, 1, 2};
        int target_sum = (prefix_sums[permutation[0]][size] + 2) / 3;

        for(int i = 0; i < 6; i++){
            int current_index = 1;
            
            while(current_index <= size && prefix_sums[permutation[0]][current_index] < target_sum) 
                current_index++;
            
            for(int second_index = current_index + 1; second_index < size; second_index++){
                if(prefix_sums[permutation[1]][second_index] - prefix_sums[permutation[1]][current_index] >= target_sum &&
                   prefix_sums[permutation[2]][size] - prefix_sums[permutation[2]][second_index] >= target_sum){
                    vii solution(3);

                    solution[permutation[0]] = {1, current_index};
                    solution[permutation[1]] = {current_index + 1, second_index};
                    solution[permutation[2]] = {second_index + 1, size};

                    for(auto segment: solution) 
                        cout << segment.first_val << ' ' << segment.second_val << ' ';
                    cout << '\n';
                    
                    solution_paisi = true;
                    break;
                }
            }
            if(solution_paisi) break;
            next_permutation(permutation.begin(), permutation.end());
        }

        if(!solution_paisi)
            cout << -1 << '\n';
    }

    return 0;
}
