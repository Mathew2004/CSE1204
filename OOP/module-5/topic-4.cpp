#include <iostream>
using namespace std;
class A{
public:
    void display(){
        cout << "Display Func" << endl;
    }
    virtual void Print() = 0; //  pure virtual function;
};    
class B : public A{
    public:
        void Print(){
            cout << "Inside Print() of class B" << endl;
        }
    };
    int main(){
        // A a; //can’t create object
        // a.Print();
        B b;
        b.Print();
        // A a;
        A *p;
        // p=&a;
        // p->Print();
        p = &b;
        p->Print();
    }
