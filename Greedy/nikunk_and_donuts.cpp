/* Nikunj loves donuts, but he also likes to stay fit. He eats n donuts in one sitting, and each donut has a calorie
count, ci. After eating a donut with k calories, he must walk at least 2^j x k(where j is the number donuts he has
already eaten) miles to maintain his weight. Given the individual calorie counts for each of the n donuts, find and
print a long integer denoting the minimum number of miles Nikunj must walk to maintain his weight. Note that he can
eat the donuts in any order.
1 ≤ n ≤ 40
1 ≤ ci ≤ 1000

custom input:
3
1 3 2
output:
11
*/

#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);

    int count = 0;
    long ans = 0;
    for(int i=n-1;i>=0;i--)
    {
        ans += arr[i] * pow(2,count);
        count++;
    }

    cout<<ans<<endl;
    return 0;
}
