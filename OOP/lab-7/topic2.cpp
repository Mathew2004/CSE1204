#include <bits/stdc++.h>
using namespace std;

template<typename T>

class A {
private:
    T x,y;

public:
    void setData(T x, T y){
        this->x = x;
        this->y = y;
    }
    T Sum(){
        return x + y;
    }
};
int main()
{
    // write required statements to call SetData() & Sum()
    A<int> a;
    a.setData(5, 7);
    cout << a.Sum() << endl;
    A<double> b;
    b.setData(5, 7.5);
    cout << b.Sum() << endl;
    A<double> c;
    c.setData(5.4, 7);
    cout << c.Sum() << endl;
    A<double> d;
    d.setData(7.5, 5);
    cout << d.Sum() << endl;
}