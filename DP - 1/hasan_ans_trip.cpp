/* There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane,
i-th city is in (Xi, Yi).
Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should
be N-th city and the sequence of cities he will visit should be increasing in index (i.e. if he is in city i he
can move to city j if and only if i < j ).
Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities), also Hasan doesn't
like traveling too much, so his happiness will decrease by total distance traveled by him.
Help Hasan by choosing a sequence of cities to visit which maximizes his happiness. */

#include <bits/stdc++.h>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    double* x = new double[n]; double* y = new double[n]; double* f = new double[n]; double* output = new double[n];
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i]>>f[i];
    output[0] = f[0];
    for(int i=1;i<n;i++)
    {
        double max_happiness = -1000000;
       	for(int j=0;j<i;j++)
       	{
           double distance = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
           if(output[j] - distance > max_happiness)
               max_happiness = output[j] - distance;
       	}
    	output[i] = max_happiness + f[i];
    }
    printf("%.6f\n", output[n-1]);
    return 0;
}
