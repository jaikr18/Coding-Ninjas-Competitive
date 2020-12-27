/* Once detective Saikat was solving a murder case.
While going to the crime scene he took the stairs and saw that a number is written on every stair.
He found it suspicious and decides to remember all the numbers that he has seen till now.
While remembering the numbers he found that he can find some pattern in those numbers.
So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the
stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.

custom input:

1
5
1 5 3 6 4

custom output:

15

*/

#include<bits/stdc++.h>
#include<unordered_map>
#include<algorithm>
using namespace std;
long long ans;

void merge(int* stairs, int left, int mid, int right)
{
    int i = left, j = mid, k = 0;
    int sorted_arr[right+1-left];
    while(i < mid && j <= right)
    {
        if(stairs[i] < stairs[j])
        {
            ans += ((right - j + 1) * stairs[i]);
            sorted_arr[k++] = stairs[i++];
        }
        else if(stairs[i] >= stairs[j])
            sorted_arr[k++] = stairs[j++];
    }
    while(i < mid)
        sorted_arr[k++] = stairs[i++];
    while(j <= right)
        sorted_arr[k++] = stairs[j++];
    for(i=left,k=0;i<=right;i++,k++)
        stairs[i] = sorted_arr[k];
}

void solve(int* stairs, int left, int right)
{
    if(right > left)
    {
        int mid = (left+right)/2;
        solve(stairs,left,mid);
        solve(stairs,mid+1,right);
        merge(stairs,left,mid + 1,right);
    }
}
int main() {

	// Write your code here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int* stairs = new int[n];
        for(int i=0;i<n;i++)
            cin>>stairs[i];
        ans = 0;
        solve(stairs,0,n-1);
        cout<<ans<<endl;
    }
    return 0;
}
