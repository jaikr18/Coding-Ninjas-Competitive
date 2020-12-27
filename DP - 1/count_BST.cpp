// Return number of unique BSTs possible with n nodes.

#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#include<math.h>
int countBST( int n)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(n == 0)
        return 0;
    long mod = pow(10,9) + 7;
	long* output = new long[n+1];
	output[0] = 1; output[1] = 1;
    for(int i=2;i<=n;i++)
    {
        long ans = 0;
        for(int j=0;j<i;j++)
        {
            ans = (ans + (output[j] * output[i-j-1]))%mod;
        }
        output[i] = ans%mod;
    }
    int ans = (int)output[n];
    return ans;
}

int main()
{
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}
