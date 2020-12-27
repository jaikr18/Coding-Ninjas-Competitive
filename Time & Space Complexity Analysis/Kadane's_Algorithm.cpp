//Program to find the max sum subarray in a given array

#include<iostream>
using namespace std;

int kadane(int* arr, int n)
{
    int curr_sum = 0;
    int best_sum = 0;
    for(int i=0;i<n;i++)
    {
        curr_sum += arr[i];
        if(best_sum < curr_sum)
            best_sum = curr_sum;
        if(curr_sum < 0)
            curr_sum = 0;
    }
    return best_sum;
}

int main()
{
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int ans = kadane(arr,n);
    cout<<ans<<endl;
    delete[] arr;
    return 0;
}
