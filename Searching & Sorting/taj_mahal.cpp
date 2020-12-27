/* Taj Mahal is one of the seven wonders of the world. Aahad loves to travel places and wants to visit Taj Mahal.
He visited Agra to view Taj Mahal. There is a ticketing system at Taj Mahal. There are total ‘n’ windows which
provide the tickets to get entry into Taj Mahal. There are ‘Ai’ people already present at each window to get the tickets.
Each window gives ticket to one person in one minute. Initially, Aahad stands in front of the first window.
After each minute, if he didn’t get the ticket, he moves on to the next window to get the ticket.
If he is at window 1, he will move to 2. If at 2nd, he will move to 3rd. If he is at last window, he will move to
1st again and so on. Find the window number at which he will get the ticket.

custom input:

4
2 3 2 0

custom output:

3

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long* windows = new long long[n];
    for(int i=0;i<n;i++)
        cin>>windows[i];

    int cnt = 0;
    int flag = 0;
    while(flag != 1)
    {
        if(windows[cnt%n] - cnt <= 0)
            flag = 1;
        else
            cnt++;
    }
    cout<<cnt%n + 1<<endl;
	return 0;
}
