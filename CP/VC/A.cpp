#include <iostream>
#include <vector>
using namespace std;

void generateString(int n) {
    string vowels = "uoiea";
    string result = "";
    
    for (int i = 0; i < n; i++) {
        result += vowels[i % 5];
    }
    

    cout << result << endl;
}

int main() {
    int t; 
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n; 
        
        generateString(n);
    }
    
    return 0;
}
