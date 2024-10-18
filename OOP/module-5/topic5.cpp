#include <iostream>
using namespace std;
class A
{
private:
    int x = 30;

public:
    void display()
    {
        cout << x << endl;
    }
    friend void Add(A &obj);
    friend void IncX(A &obj, int m);
    friend void DecX(A &obj, int n);
};
void Add(A &obj)
{
    cout << obj.x << endl;
}
void IncX(A &obj, int m)
{
    obj.x += m;
    cout << obj.x << endl;
}
void DecX(A &obj, int n)
{
    obj.x -= n;
    cout << obj.x << endl;
}
int main()
{
    A a;
    Add(a);
    IncX(a, 5);
    DecX(a, 6);
}
