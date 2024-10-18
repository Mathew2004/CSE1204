#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    double a,b,c,d,l,r;
	cin >> a >> b >> c>> d>> l >> r;
	if((b-d)*(c-l) == (d-r)*(a-c))
	{
	    cout << "TOWARDS";
	}
	else if((b-d)*(c-l) > (d-r)*(a-c))
	{
	    cout << "RIGHT";
	}
	else if((b-d)*(c-l) < (d-r)*(a-c))
	{
	    cout << "LEFT";
	}
}