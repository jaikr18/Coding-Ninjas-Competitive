/* Shreya loves to eat momos. Her mother gives her money to buy vegetables but she manages to save some money
out of it daily. After buying vegetables, she goes to "Momos Market", where there are ‘n’ number of shops of momos.
Each of the shops of momos has a rate per momo. She visits the market and starts buying momos (one from each shop)
starting from the first shop. She will visit the market for ‘q’ days. You have to tell that how many momos she can
buy each day if she starts buying from the first shop daily. She cannot use the remaining money of one day on some
other day. But she will save them for other expenses in the future, so, you also need to tell the sum of money left
with her at the end of each day.

custom input:

6
3 3 2 8 5 8 4
4
2
25
17

custom output:

1 1
0 2
5 4
4 1

*/

#include<bits/stdc++.h>
#include<algorithm>
#include<utility>
using namespace std;

pair<int,long long> is_possible(int* shops, int n, long long money)
{
    long long left_money = money;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(left_money >= shops[i])
        {
            cnt++;
            left_money -= shops[i];
        }
        else
            break;
    }
    return make_pair(cnt,left_money);
}

int main()
{
    int n;
    cin>>n;
    int* shops = new int[n];
    for(int i=0;i<n;i++)
        cin>>shops[i];

    int q;
    cin>>q;
    while(q--)
    {
        long long money, left_money;
        cin>>money;
        if(money < shops[0])
        {
            cout<<0<<" "<<money<<endl;
            continue;
        }
        pair<int,long long> poss = is_possible(shops,n,money);
        cout<<poss.first<<" "<<poss.second<<endl;
    }
	return 0;
}
