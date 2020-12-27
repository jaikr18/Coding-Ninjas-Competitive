/* Given two binary strings s and t, make s equal to t by performing a number of operations as follows:
flip s[i], the cost will be 1.
swap s[i] with s[j], the cost will be |i - j|.
minimize the cost. */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;
    int n = s.size();
    int cost = 0;
    for(int i = 0; i < n;)
    {
        if(s[i] != t[i])
        {
            if(i + 1 < n && s[i+1] != t[i+1] && s[i] != s[i+1])
            {
                cost++;
                i += 2;
            }
            else
            {
                cost++;
                i++;
            }
        }
    }
    cout<<cost<<endl;
    return 0;
}
