/* Harshit gave Aahad an array of size N and asked to minimize the difference between the maximum value and minimum value
by modifying the array under the condition that each array element either increase or decrease by k(only once).

custom input:
3 6
1 15 10

output:
5 */

#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,k; cin>>n>>k;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    int ans = arr[n-1] - arr[0];
    arr[0] += k; arr[n-1] -= k;
    if(arr[0] > arr[n-1])
    {
        int temp = arr[0];
        arr[0] = arr[n-1];
        arr[n-1] = temp;
    }
    int small = arr[0], big = arr[n-1];

    for(int i=1;i<n-1;i++)
    {
        int sub = arr[i] - k, add = arr[i] + k;
        if(sub >= small || add <= big)
            continue;
        else
        {
            if(big - sub <= add - small)
                small = sub;
            else
                big = add;
        }
    }

    cout<<min(ans, big - small);
}
