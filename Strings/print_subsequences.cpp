#include<string>
#include<bits/stdc++.h>
using namespace std;

void printkeypad(string s, string output)
{
    if(s.size() == 0)
    {
        cout<<output<<endl;
        return;
    }

    printkeypad(s.substr(1),output);
    printkeypad(s.substr(1),output + s[0]);
}

int main()
{
    string s;
    cin>>s;
    string output = "";
    printkeypad(s,output);
    return 0;
}
