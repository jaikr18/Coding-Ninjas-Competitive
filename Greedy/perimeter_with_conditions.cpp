/* Aahad gives an array of integers and asks Harshit to find which three elements form a triangle (non-degenerate).
The task seems easy to Harshit.
So, Aahad adds some conditions to this task -
1. Find the triangle with maximum perimeter
2. If there are two or more combinations with same value of maximum perimeter, then find the one with the longest side.
3.If there are more than one combinations which satisfy all the above conditions the find with maximum longest minimum side.

custom input:
5
1 1 1 3 3

output:
1 3 3
*/

#include<bits/stdc++.h>
#include<climits>
#include<algorithm>
using namespace std;
int main() {
	int n; cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n,greater<int>());
    int* fans = new int[3];

    int ans = INT_MIN;
    for(int i=0;i<n-2;i++)
    {
        if(arr[i] < arr[i+1] + arr[i+2])
        {
        	int poss = arr[i] + arr[i+1] + arr[i+2];
            if(poss > ans)
            {
                ans = poss;
                fans[0] = arr[i+2]; fans[1] = arr[i+1]; fans[2] = arr[i];
            }
        }
    }

	for(int i=0;i<3;i++)
        cout<<fans[i]<<" ";
	return 0;
}
