/* Given n concentric rectangles symmetric to the origin, calculate the total area covered by all the rectangles. */

#include<bits/stdc++.h>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int* height = new int[5000000 + 2]();
    int max_x = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int l,b,x;
        cin>>l>>b;
        x = l/2;
        if(height[x] < b)
            height[x] = b;
        if(x > max_x)
            max_x = x;
    }

    long area = 0;
    for(int i=max_x;i>0;i--)
    {
        if(height[i] < height[i+1])
            height[i] = height[i+1];
        area += height[i];
    }

    cout<<2 * area<<endl;
    return 0;
}
