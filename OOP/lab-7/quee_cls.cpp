#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    queue<int>qu;
    qu.push(4);
    cout<<qu.front()<<" "<<qu.back()<<endl;
    qu.push(10);
    cout<<qu.front()<<" "<<qu.back()<<endl;
    qu.push(12);
    cout<<qu.front()<<" "<<qu.back()<<endl;
    qu.push(8);
    cout<<qu.front()<<" "<<qu.back()<<endl;

    cout<<endl;

    qu.pop();
    cout<<qu.front()<<" "<<qu.back()<<endl;
    qu.pop();
    cout<<qu.front()<<" "<<qu.back()<<endl;
    qu.pop();
    cout<<qu.front()<<" "<<qu.back()<<endl;
    if(qu.empty()==0){
        cout<<"Queue is not Empty"<<endl;
    }
    else{
        cout<<"Queue is Empty"<<endl;
    }
}

