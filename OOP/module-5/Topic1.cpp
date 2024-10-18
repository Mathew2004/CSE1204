#include<bits/stdc++.h>
using namespace std;

class Test{
    public:
        void Sum(int a){
            cout << a << endl;
        }
        void Sum(int a, int b){
            cout << a+b << endl;
        }
        void Sum(double a, int b){
            cout << a+b << endl;
        }
        void Sum(int a, double b){
            cout << a+b << endl;
        }
        void Sum(double a, double b){
            cout << a+b << endl;
        }
};


int main(){
Test t;
 t.Sum(10); //returns 10
 t.Sum(10,20); //return 30
 t.Sum(5.7,20); //return 25.7
 t.Sum(10,2.6); //return 12.6
 t.Sum(10.5,20.7); //return 21.2

}