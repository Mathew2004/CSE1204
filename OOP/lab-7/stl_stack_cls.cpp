#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<int>st;

    st.push(4);
    cout<<st.top()<<endl;
    st.push(10);
    cout<<st.top()<<endl;
    st.push(12);
    cout<<st.top()<<endl;
    st.push(8);
    cout<<st.top()<<endl;

    cout<<endl;

    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    if(st.empty()==0){
        cout<<"Stack is not Empty"<<endl;
    }
    else{
        cout<<"Stack is Empty"<<endl;
    }
}
