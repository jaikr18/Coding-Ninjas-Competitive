#include <bits/stdc++.h>
using namespace std;
int check = pow(10,9) + 7;
long long decode(string s, int size)
{
    long long* output = new long long[size+1];
    output[0] = 1; output[1] = 1;
    for(int i=2;i<=size;i++)
    {
        if(s[i-1] == '0')
        {
            if(s[i-2] > '2' || s[i-2] == '0')
                return 0;
            output[i] = output[i-2];
            continue;
        }
        output[i] = output[i-1];
        if(s[i-2] != '0' && s[i-2] < '2' || ((s[i-2] == '2') && s[i-1] <= '6'))
            output[i] = (output[i] + output[i-2])%check;
    }
	long long ans = output[size];
    delete[] output;
    return ans;
}

int main()
{
    while(1)
    {
        string s;
        cin>>s;
        if(s[0] == '0')
            return 0;
        int size = s.size();
        long long ans = decode(s,size);
        long final = ans%check;
        cout<<final<<endl;
    }
    return 0;
}
