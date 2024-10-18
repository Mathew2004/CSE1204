#include<bits/stdc++.h>
using namespace std;

class A{
    private:
        int r,im;
    public:
        A(int a=0, int b=0):r(a),im(b){};
        // A(int a, int b):r(a),im(b){};

        A operator+(A const &obj){
            A temp;
            temp.r = r + obj.r;
            temp.im = im + obj.im;
            return temp;
        }

        // Prefix Sum
        void operator++(){
            r = r+1;
            im = im+1;
        }
    // Postfix sum
        A operator++(int){
            A temp = *this; //store old value
            r = r+1;     // increment data
            im = im+1;      // increment data
            return temp; // return store value
        }

        void operator--(){
            r -= 1;
            im -= 1;
        }

        A operator--(int)
        {
            A temp = *this;
            r -= 1;
            im -= 1;
            return temp;
        }

        void dispaly(){
            cout<<r<<" + "<<im<<"i"<<endl;
        }

        // int sum(int a, int b , int c){
        //     return a+b+c ;
        // }
        // double sum(double a, double b){
        //     return a+b ;
        // }
        // A operator+(A const &obj ){
        //     return *this->sum;
        // }

};


int main(){
    A a(3,5), b(3,5);
    A c(1,2);
    ++c ;
    c++;
    --c;
    c--;
    c.dispaly();
    // cout << a.sum(1,2,3)+ a.sum(1.5,2.5);
}