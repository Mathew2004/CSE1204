#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    tuple<int,string,double>tx;
    tx=make_tuple(100,"Kamal",3.5);
    cout<<get<0>(tx)<<endl;
    cout<<get<1>(tx)<<endl;
    cout<<get<2>(tx)<<endl;
    get<2>(tx)=3.7;
    cout<<get<2>(tx)<<endl;
    tuple<int,string,double>bx;
    bx=make_tuple(85,"Evan",3.4);
    tuple<int,string,double>ax;
    ax.swap(bx);
    cout<<get<0>(ax)<<endl;
    cout<<get<1>(ax)<<endl;
    cout<<get<2>(ax)<<endl;
}
