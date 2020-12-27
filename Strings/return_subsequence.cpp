#include<string>
#include<math.h>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int subsequences(string s, string* output)
{
    int count = 0;
    if(s.size() == 0)
    {
        output[count] = "";
        return 1;
    }
    int small_array = subsequences(s.substr(1),output);
    for(int i = 0;i<small_array;i++)
       output[small_array + i] = s[0] + output[i];
    count += (2 * small_array);
    return count;
}

int main()
{
    string s;
    cin>>s;
    int len = s.size();
    int size = pow(2,len);
    string* output = new string[size];
    int c = subsequences(s,output);
    for(int i = 0;i<c;i++)
        cout<<output[i]<<endl;
    return 0;
}
