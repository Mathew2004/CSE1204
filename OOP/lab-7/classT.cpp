#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class A{
private:
    T x;
    T y;
public:
    void setData(T x,T y){
        this->x=x;
        this->y=y;
    }
    T Sum()
    {
        return x+y;
    }
};
int main()
{
    A <int>p;
    p.setData(2,3);
    cout<<"SUM of (int+int) = "<<p.Sum()<<endl;

    A <float>q;
    q.setData(3.6,3);
    cout<<"SUM of (double+int) = "<<q.Sum()<<endl;

    A <float>r;
    r.setData(2,3.9);
    cout<<"SUM of (int+double) = "<<r.Sum()<<endl;

    A <float>s;
    s.setData(4.5,3.2);
    cout<<"SUM of (double+double) = "<<s.Sum()<<endl;
}
