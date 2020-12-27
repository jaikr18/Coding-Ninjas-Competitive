/* A bulb can be ‘ON’ or ‘OFF’. Mr. Navdeep got ‘n’ number of bulbs and their status, whether they are ‘ON’ or ‘OFF’.
Their status is represented in a string of size ‘n’ consisting of 0’s and 1’s, where ‘0’ represents the bulb is in ‘OFF’
condition and ‘1’ represent the bulb is ‘ON’. Mr. Navdeep has been given the task to light up all the bulbs.

He can perform two operations.
First, chose any segment of bulbs and reverse them means chose any substring and reverse it.
E.g. “0 110 001” -> “0 011 001”. Substring (1, 3) is reversed here. This operation will cost him Rs. ‘X’.

Second, chose any segment of bulbs and reverse their present condition. i.e. if the bulb is ‘ON’, make it ‘OFF’
and if it is ‘OFF’, make it ‘ON’.
E.g. “0 011 001” -> “0 100 001”. Substring (1, 3) is complemented. This operation will cost him Rs. ‘Y’.

You need to help Mr. Navdeep that how much minimum amount it will require to make all the bulbs lightened.
(or make all the characters as ‘1’ in the representation string) */

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    long long n,x,y;
    cin>>n>>x>>y;
    string states;
    cin>>states;
    long long n_groups = 0, toggle = 0, ans = 0;

    for(int i=1;i<n;i++)
    {
        if(states[i] == '1' && states[i-1] == '0' && toggle == 0)
            n_groups++;
        else if(states[i] == '0' && states[i-1] == '1')
        {
            n_groups++;
            toggle = 1;
        }
    }

    if(n_groups == 0)
    {
        if(states[0] == '0')
        {
            ans = y;
            cout<<ans<<endl;
            return 0;
        }
        cout << 0 <<endl;
        return 0;
    }

    if(n_groups == 1)
    {
        ans = y;
        cout<<ans<<endl;
        return 0;
    }

    ans = (((n_groups-1)*min(x,y)) + y);
    cout << ans << endl;
	return 0;
}
