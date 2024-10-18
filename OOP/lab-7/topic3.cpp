#include <bits/stdc++.h>
// Include this header for std::out_of_range

using namespace std;

int main()
{
    array<int, 6> ax = {10,60,30,70,20};
    // Getting 2nd element
    cout << "3rd Element of ax array - " << ax.at(2) << endl;
    cout << "1st Element of ax array - " << ax.front() << endl;
    cout << "Last Element of ax array - " << ax.back() << endl;

    // Fill ax with 10 using fill()
    ax.fill(10);
    for(auto i: ax) cout << i << " ";
    cout << endl;

    // Check Array is empty or not
    if(ax.empty()){
        cout << "Array is empty" << endl;
    }else{
        cout << "Array is not empty" << endl;
    }

    // SIze of ax
    cout << "Size of ax - " << ax.size() << endl;
    cout << "Max size of ax - " << ax.max_size() << endl;
    cout << "Address of first element of ax - " << ax.begin() << endl;
    cout << "Address of last element of ax - " << ax.end() << endl;
}