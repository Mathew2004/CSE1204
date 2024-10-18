#include <bits/stdc++.h>
using namespace std;
int main(){
    array <int,6> ax={10,60,30,20,70};
    cout<<"The 3rd element of the array 'ax' = "<<ax.at(2)<<endl;
    cout<<"First element of the array 'ax' = "<<ax.front()<<endl;
    cout<<"Last element of the array 'ax' = "<<ax.back()<<endl;

    for(auto x:ax)
        cout<<x<<" ";
    cout<<endl;

    ax.fill(10);
    cout<<"Last element of the array 'ax' = "<<ax.back()<<endl;

    if(ax.empty()==1){
        cout<<"EMPTY ARRAY"<<endl;
    }
    else{
        cout<<"NOT AN EMPTY ARRAY"<<endl;
    }

    cout<<"Size of the array = "<<ax.size()<<endl;
    cout<<"Max Size of the array = "<<ax.max_size()<<endl;
    cout<<"Address of the first element = "<<ax.begin()<<endl;
    cout<<"Address of the Last element = "<<ax.end()<<endl;
}
