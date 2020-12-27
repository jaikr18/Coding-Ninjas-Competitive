#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int LCS_recursive(string s1, string s2)
{
    if(s1.empty() || s2.empty())
        return 0;
    if(s1[0] == s2[0])
        return 1 + LCS_recursive(&s1[1], &s2[1]);
    else
    {
        int potential_ans1 = 0, potential_ans2 = 0;
        potential_ans1 = LCS_recursive(&s1[1], s2);
        potential_ans2 = LCS_recursive(s1, &s2[1]);
        return max(potential_ans1, potential_ans2);
    }
}

LCS_recursive_better(string s1, string s2, int size1, int size2, int** dp)
{
    if(size1 == 0 || size2 == 0)
        return 0;
    else if(dp[size1][size2] >= 0)
        return dp[size1][size2];

    int ans;
    if(s1[0] == s2[0])
        ans = LCS_recursive_better(&s1[1], &s2[1], size1-1, size2-1, dp);
    else
    {
        int potential_ans1 = 0, potential_ans2 = 0;
        potential_ans1 = LCS_recursive(&s1[1], s2);
        potential_ans2 = LCS_recursive(s1, &s2[1]);
        ans = max(potential_ans1, potential_ans2);
    }

    dp[size1][size2] = ans;
    return ans;
}

int LCS_recursive_better_helper(string s1, string s2)
{
    int size1 = s1.size(), size2 = s1.size();
    int** dp = new int*[size1 + 1];
    for(int i=0;i<=size1;i++)
    {
        dp[i] = new int[size2 + 1];
        for(int j=0;j<=size2;j++)
            dp[i][j] = -1;
    }

    int ans = LCS_recursive_better(s1, s2, size1, size2, dp);

    for(int i=0;i<=size1;i++)
        delete[] dp[i];
    delete[] dp;

    return ans;
}

LCS_iterative(string s1, string s2)
{
    int m = s1.size(), n = s2.size();
    int** dp = new int*[m + 1];
    for(int i=0;i<=m;i++)
        dp[i] = new int[n + 1]();

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(s1[m-i] == s2[n-j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    int ans = dp[m][n];
    for(int i=0;i<=m;i++)
        delete[] dp[i];
    delete[] dp;

    return ans;
}

int main()
{
    cout<<"\t\tLONGEST COMMON SUBSEQUENCE"<<endl<<endl;
    string s1, s2;
    cout<<"Enter the first string: ";
    cin>>s1;
    cout<<"\nEnter the second string: ";
    cin>>s2;
    int ans = LCS_recursive(s1, s2);

    ans = LCS_recursive_better_helper(s1, s2);
    cout<<ans<<endl;

    ans = LCS_iterative(s1, s2);
    cout<<ans<<endl;

    return 0;
}
