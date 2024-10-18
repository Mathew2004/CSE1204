#include <bits/stdc++.h>
using namespace std;

class Bank
{
private:
    int total = 0;
    string userName[5];
    string password[5];
    int balance[5];

public:
    int check(string name, string pass)
    {
        for (int i = 0; i < total; i++)
        {
            if (userName[i] == name && password[i] == pass)
            {
                return i;
            }
        }
        return -1;
    }
    void NewAccount()
    {
        if (total > 2)
        {
            int press;
            cout << "The Maximum Account Limir has Reached. You can't Open any new accounts. If you want to Delete Previous account press 1";
            cin >> press;
            if (press == 1)
            {
                DeleteAccount();
            }
            return;
        }
        else
        {
            string name, pass;
            int bal;
            cout << "Enter Your Name: ";
            cin >> name;
            cout << "Enter Your Password: ";
            cin >> pass;
            cout << "Enter Your Balance: ";
            cin >> bal;
            userName[total] = name;
            password[total] = pass;
            balance[total] = bal;
            total++;
        }
    }

    void Withdraw()
    {
        string name, pass;
        int bal;
        cout << "Enter Your Name: ";
        cin >> name;
        cout << "Enter Your Password: ";
        cin >> pass;
        int index = check(name, pass);
        if (index == -1)
        {
            cout << "Invalid Credential" << endl;
        }
        else
        {
            cout << "Login Successful...";

            cout << "Enter The Amount you want to Withdraw: ";
            cin >> bal;

            if (bal > balance[index])
            {
                cout << "Insuffetiant Balance, You can't withdraw this amount" << endl;
            }
            else
            {
                balance[index] -= bal;
                cout << "Transaction Successful...";
                cout << "Your Updared balance is: " << balance[index] << endl;
            }
        }
    }
    void Deposit()
    {
        string name, pass;
        int bal;
        cout << "Enter Your Name: ";
        cin >> name;
        cout << "Enter Your Password: ";
        cin >> pass;
        int index = check(name, pass);
        if (index == -1)
        {
            cout << "Invalid Credentials" << endl;
        }
        else
        {
            cout << "Login Successful...";

            cout << "Enter The Amount you want to Deposit: ";
            cin >> bal;

            balance[index] += bal;
            cout << "Transaction Successful...";
            cout << "Your Updared balance is: " << balance[index] << endl;
        }
    }

    void DeleteAccount()
    {
        userName[total] = "";
        password[total] = "";
        balance[total] = 0;
        total--;
    }

    void Display()
    {
        cout << userName << " " << password << " " << balance << " ";
    }
};

int main()
{
    Bank b;
    int opt;

    while (1)
    {
        cout << "Welcome To The Bank! " << endl;
        cout << "Press 1 to Open New Account " << endl;
        cout << "Press 2 to Withdraw Amount " << endl;
        cout << "Press 3 to Deposit Amount " << endl;
        cout << "Press 4 to Exit Program " << endl;
        cin >> opt;
        if (opt == 4)
            break;

        if (opt == 1)
        {
            // cout << "New Acc" << endl;
            b.NewAccount();
            continue;
            ;
        }
        else if (opt == 2)
        {
            // cout << "Withdraw";
            b.Withdraw();
            continue;
        }
        else if (opt == 3)
        {
            // cout << "Deposit";
            b.Deposit();
            continue;
        }
        else
        {
            cout << "Invalid Option";
            continue;
        }
    }
    // b.Display();
}