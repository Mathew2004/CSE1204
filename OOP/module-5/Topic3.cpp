#include<bits/stdc++.h>
using namespace std;

class A{
    public:
     virtual  void Print(){
        cout<<"Inside of Print A"<<endl;
       }
};

class B: public A{
    public:
        void Print(){
            cout<<"Inside of Print()  B"<<endl;
        }
};


int main(){
    A a;
    B b;
    a.Print();
    b.Print();
    A *p;
    p = &a;
    p->Print();
    p = &b;
    p->Print();

}