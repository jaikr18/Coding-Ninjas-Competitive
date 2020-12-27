/* Gary is bored and wants to play an interesting but tough game. So he figured out a new board game called
"destroy the neighbors" . In this game there are N integers on a board. In one move, he can pick any integer x
from the board and then all the integers with value x+1 or x-1 gets destroyed .This move will give him x points.

NOTE: In other words, we have to maximize the sum of such given array with the constraint that if we pick a number x from the array, we cannot pick x-1 and x+1
for our sum. */

#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int>A;


int solve(int n,vector<int>A){
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
	int* frequency = new int[1001];
    for(int i=0;i<=1000;i++)
        frequency[i] = 0;
    for(int i=0;i<n;i++)
        frequency[A[i]]++;

    int* ans = new int[1001];
    ans[0] = 0; ans[1] = 1 * frequency[1];
    for(int i=2;i<=1000;i++)
    {
        ans[i] = max(ans[i-2] + frequency[i]*i, ans[i-1]);
    }

    return ans[1000];
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	cout<<solve(n,A)<<endl;
}
