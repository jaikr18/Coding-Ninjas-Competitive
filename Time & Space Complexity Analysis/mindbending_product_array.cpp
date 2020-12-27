//from a given array A, create a new array P such that P[i] is the product of all A except A[i].
//example A = 10 3 5 6 2, P = 180 600 360 300 900

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int* arr = new int[n];
    int* p = new int[n];
    p[0] = 1;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i > 0)
            p[i] = p[i-1] * arr[i-1];
    }
    int rp = 1;
    for(int i = n-2;i>=0;i--)
    {
        rp *= arr[i+1];
        p[i] *= rp;
    }
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" "<<endl;
    }
    return 0;
}
