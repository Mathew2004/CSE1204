#include <bits/stdc++.h>
using namespace std;
class Circuit
{
private:
    int real;
    int img;
    float current;

public:
    Circuit()
    {
    }
    Circuit(int a, int b)
    {
        real = a;
        img = b;
    }
    Circuit operator+(Circuit cr)
    {
        Circuit temp;
        temp.real = real + cr.real;
        temp.img = img + cr.img;
        return temp;
    }
    Circuit operator/(Circuit plx)
    {
        Circuit tmp;
        tmp.current = sqrt((real) * (real) + (img) * (img)) / sqrt((plx.real) * (plx.real) + (plx.img) * (plx.img));
        return tmp;
    }
    void display()
    {
        cout << real << " + j" << img << endl;
    }
    void display_curr()
    {
        cout << current << endl;
    }
};
int main()
{
    Circuit z1(3, 4), z2(4, -3), z3(0, 6), volt(100, 50);
    Circuit total = z1 + z2 + z3;
    Circuit Current = volt / total;
    total.display();
    Current.display_curr();
}
