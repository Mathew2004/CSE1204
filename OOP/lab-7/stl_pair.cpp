#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    pair<int,string>px;
    px=make_pair(10,"Rajshahi");
    cout<<"int data member = "<<px.first<<endl;
    cout<<"string data member = "<<px.second<<endl;
    get<0>(px)=20;
    cout<<"int data member [after updating] = "<<px.first<<endl;
    pair<int,string>bx;
    bx={30,"Dhaka"};
    px.swap(bx);
    cout<<"int data member of px [after swapping] = "<<px.first<<endl;
    cout<<"string data member of px [after swapping] = "<<px.second<<endl;
}
