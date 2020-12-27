/* Harshit knows by his resources that this time the winning lottery number is the smallest number whose sum of the
digits is S and the number of digits is D. You have to help Harshit and print the winning lottery number.

custom input:
9 2

output: 18 */

#include<bits/stdc++.h>
using namespace std;
int main() {
	int s,d;
    cin>>s>>d;
    int* num = new int[d];
    num[0] = 1;
    for(int i=d-1;i>=1;i--)
    {
        if(s-1 <= 9)
        {
            num[i] = s-1;
            s = 1;
        }
        else
        {
            num[i] = 9;
            s -= 9;
        }
    }
    num[0] = s;
    for(int i=0;i<d;i++)
        cout<<num[i];
}
