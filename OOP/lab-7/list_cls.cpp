#include <iostream>
#include <bits/stdc++.h>
#include <iterator>
#include <algorithm>
using namespace std;

void display_all(list<int>&l)
{
    for(auto it=l.begin(); it!=l.end(); it++){
        cout<<*it<<" ";
    }
}
void display_rev(list<int>&l)
{
    for(auto pt=l.rbegin(); pt!=l.rend(); pt++){
        cout<<*pt<<" ";
    }
}
int main(){
    list<int>li;
    li.push_back(10);
    li.push_back(20);
    li.push_back(30);
    li.push_back(40);
    li.push_back(50);
    li.push_back(60);
    li.push_back(70);
    li.push_back(80);

    li.push_front(-10);
    li.push_front(-20);
    display_all(li);
    cout<<endl;
    display_rev(li);
    cout<<endl;

    cout<<li.front()<<endl;
    cout<<li.back()<<endl;

    li.pop_front();
    display_all(li);
    cout<<endl;

    li.pop_back();
    display_all(li);
    cout<<endl;

    int x=30;
    auto it=find(li.begin(), li.end(), x);
    if (it!=li.end()) {
        cout<<"Element "<<x<<" found at position "<<distance(li.begin(), it)<<endl;
    } else {
        cout<<"Element "<<x<<" not found in the list"<<endl;
    }

    int y=40;
    int newElement=35;
    it=find(li.begin(), li.end(), y);
    if (it!=li.end()) {
        li.insert(it, newElement);
    }
    display_all(li);
    cout<<endl;

    y=50;
    newElement=55;
    it=find(li.begin(), li.end(), y);
    if (it!=li.end()) {
        advance(it, 1);
        li.insert(it, newElement);
    }
    display_all(li);
    cout<<endl;

    x=30;
    int countX=count(li.begin(), li.end(), x);
    cout<<"Count of "<<x<<": "<<countX<<endl;

    int conditionCount=count_if(li.begin(), li.end(), [](int val) {
        return val>=40 && val<=60;
    });
    cout<<"Count with condition: "<<conditionCount<<endl;

    x=60;
    it=find(li.begin(), li.end(), x);
    if (it!=li.end()) {
        li.erase(it);
    }
    display_all(li);
    cout<<endl;

    it=li.begin();
    advance(it, 4);
    li.erase(li.begin(), it);
    display_all(li);
    cout<<endl;

    x=40;
    li.remove(x);

    li.remove_if([](int val) {
        return val < 0;
    });
    display_all(li);
    cout<<endl;

    list<int> anotherList={100, 200, 300};
    li.assign(anotherList.begin(), anotherList.end());
    display_all(li);
    cout<<endl;

    int arr[]={1, 2, 3};
    li.assign(arr, arr + sizeof(arr) / sizeof(arr[0]));
    display_all(li);
    cout<<endl;

    li.sort();
    display_all(li);
    cout<<endl;

    li.unique();
    display_all(li);
    cout<<endl;

    return 0;
}
