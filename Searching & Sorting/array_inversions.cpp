/* Find and return the number of inversions in the a=given array.
custom input: 5
              2 5 1 3 4
custom output: 4 */

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005

long long merge_arr(int A[], int left, int mid, int right)
{
    int i = left, j = mid, k = 0;
    long long count = 0;
    int sorted_arr[right+1-left];
    while(i<mid && j<=right)
    {
        if(A[i] <= A[j])
            sorted_arr[k++] = A[i++];
        else
        {
            sorted_arr[k++] = A[j++];
            count += mid - i;
        }
    }
    while(i < mid)
        sorted_arr[k++] = A[i++];
    while(j <= right)
        sorted_arr[k++] = A[j++];
    for(int i=left,k=0;i<=right;i++,k++)
        A[i] = sorted_arr[k];
    return count;
}

long long merge_sort(int A[], int left, int right)
{
    long long count = 0;
    if(right > left)
    {
        int mid = (left+right)/2;
        long long left_ans = merge_sort(A,left,mid);
        long long right_ans = merge_sort(A,mid+1,right);
        long long merge_ans = merge_arr(A,left,mid+1,right);
        return left_ans + right_ans + merge_ans;
    }
    return count;
}


long long solve(int A[], int n)
{
	long long ans = merge_sort(A,0,n-1);
	return ans;
}

int main()
{
	int n,A[MAXN];
	cin>>n;
	for(int i = 0; i < n ; i++){
		cin>>A[i];
	}
	cout<<solve(A,n)<<endl;
}
