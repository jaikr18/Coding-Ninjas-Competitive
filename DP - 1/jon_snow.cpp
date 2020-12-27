#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k ,x;
    cin>>n>>k>>x;
    int* arr = new int[1001]();
    int* arr2 = new int[1001]();
    for(int i=0;i<n;i++)
    {
        int ranger;
        cin>>ranger;
        arr[ranger]++;
    }
	for(int i=0;i<k;i++)
    {
        int count = 0;

        for(int j=0;j<=1000;j++)
            arr2[j] = arr[j];

        for(int j=0;j<=1000;j++)
        {
            if(arr2[j] > 0)
            {
                int new_val = j^x, new_val_count = 0;
            	if(count%2 == 0)
                	new_val_count = (arr[j]+ 1)/2;
                else
                    new_val_count = arr[j]/2;
                count += arr[j];
                arr2[j] -= new_val_count;
                arr2[new_val] += new_val_count;
            }
        }

        for(int j=0;j<=1000;j++)
            arr[j] = arr2[j];
    }

    for(int i=1000;i>=0;i--)
    {
        if(arr[i] > 0)
        {
            cout<<i<<" ";
            break;
        }
    }

    for(int i=0;i<=1000;i++)
    {
        if(arr[i] > 0)
        {
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}
