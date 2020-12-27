//program to find the maximum product subarray ina given array

#include<iostream>
using namespace std;
typedef long long ll;

ll max_product_subarray(int* arr, int n)
{
    ll final_max = INT_MIN, curr_max = 1, curr_min = 1;
    for(int i=0;i<n;i++)
    {
        ll checker = 1;
        if(arr[i] > 0)
        {
            curr_max *= arr[i];
            curr_min = min( checker , curr_min * arr[i]);
        }
        else if(arr[i] < 0)
        {
            ll temp = curr_max;
            curr_max = max(curr_max , curr_min * arr[i]);
            curr_min = min(curr_min, temp * arr[i]);
        }
        else
        {
            curr_max = 1;
            curr_min = 1;
        }
        if(final_max < curr_max)
            final_max = curr_max;
    }
    return final_max;
}

int main()
{
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    ll ans = max_product_subarray(arr,n);
    cout<<ans<<endl;
    return 0;
}
