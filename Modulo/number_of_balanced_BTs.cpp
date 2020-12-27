#include <iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#include <cmath>

int balancedBTs(int h) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return the output and don’t print it.
  */
    int c = pow(10,9) + 7;
	int* answers = new int[h+1];
    answers[0] = 1; answers[1] = 1;
    for(int i=2;i<=h;i++)
    {
        int x = answers[i-1], y = answers[i-2];
        long res1 = (long)x*x;
        long res2 = (long)2*x*y;
        int ans1 = (int)(res1 % c);
        int ans2 = (int)(res2 % c);
        answers[i] = (ans1 + ans2)%c;
    }
    return answers[h];
}

int main() {
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}
