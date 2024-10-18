#include <iostream>
#include <stdexcept> // Include this header for std::out_of_range

using namespace std;

int main()
{
    int i;
    int ax[5] = {10, 20, 60, 40, 30};
    cout << "enter index:";
    cin >> i;
    try
    {
        if (i > 0 && i < 5)
        {
            cout << "ax[" << i << "]=" << ax[i] << endl;
            throw i;
        }
        if (i >= 5 || i < 0)
        {
            throw "Out of Range Error!!!";
        }
    }
    catch (int i)
    {
        cout << "Value of i = " << i << endl;
    }
    catch (char const *str){
        cout << str << endl;
    }
    catch (...)
    {
        cout << "An ERROR occurred" << endl;
    }

    return 0;
}