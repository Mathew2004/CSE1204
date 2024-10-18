#include<bits/stdc++.h>
using namespace std;

// class A{
//     public:
//        virtual void print(){
//             cout << "Inside of A" << endl;
//         }
//        virtual void show(){
//             cout << "Show A" << endl;
//         }
// };

// class B: public A{
//     public:
//         void print(){
//             cout << "Inside of B" << endl;
//         }
//         void show(){
//             cout << "Show B" << endl;
//         }
        
// };

class Animal{
    public:
        virtual void eat() = 0;
};

class Cat: public Animal{
    public:
    void eat(){ 
        cout << "Cat is eating" << endl;
    }
};
class Dog: public Animal{
    public:
    void eat(){ 
        cout << "Dog is eating" << endl;
    }
};


void show(Animal *a){
    a->eat();
}

int main(){
    Animal *pb;
    Cat c;
    pb = &c;
    show(pb);
    Dog d;
    pb = &d;
    show(pb);
}