#include<iostream>
using namespace std;

int longestBitonicSubarray(int *input, int n) {

	/* Don't write main().
     	* the input is already passed as function argument.
     	* Taking input and printing output is handled automatically.
     	*/
    	int* inc = new int[n+1];
    	int* dec = new int[n+1];
    	for(int i=0;i<=n;i++)
        {
            inc[i] = 1; dec[i] = 1;
        }
        inc[0] = 1; inc[1] = 1; dec[0] = 1; dec[1] = 1;
        for(int i=2;i<=n;i++)
        {
            for(int j=i-1;j>0;j--)
            {
                if(inc[j] >= inc[i] && input[i-1] > input[j-1])
                    inc[i] = inc[j] + 1;
            }
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=i-1;j>0;j--)
            {
                if(dec[j] >= dec[i] && input[n-i] > input[n-j])
                    dec[i] = dec[j] + 1;
            }
        }

        /* for(int i=0;i<=n;i++)
            cout<<inc[i]<<" "<<dec[i]<<endl; */

        int* ans = new int[n+1];
        ans[0] = 1; int max = 0;
        for(int i=1;i<=n;i++)
        {
            ans[i] = inc[i] + dec[n+1-i];
            if(ans[i] > max)
                max = ans[i];
        }
     	return max-1;
 	}



int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubarray(input, n);
  return 0;
}

