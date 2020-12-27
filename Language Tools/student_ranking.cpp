#include<string>
#include<utility>
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string,int> p1, pair<string,int> p2)
{
    return p1.second > p2.second;
}
int main()
{
    int n;
    cin>>n;
    pair<string,int>* student_details = new pair<string,int>[n];
    for(int i=0;i<n;i++)
    {
        string student;
        getline(cin,student);
        string name = "";
        int marks = 0;
        for(int j=0;student[j] != '\0';)
        {
            if(isalpha(student[j]))
                name += student[j++];
            else if(isdigit(student[j]))
            {
                if(student[j+1] != '\0' && isdigit(student[j+1]))
                {
                    if(student[j+2] != '\0' && isdigit(student[j+2]))
                    {
                        marks += 100;
                        j += 3;
                        continue;
                    }
                    marks = marks + 10*(student[j] - 48) + (student[j+1] - 48);
                    j += 2;
                    continue;
                }
                marks = marks + (student[j] - 48);
                j++;
            }
        }
        cout<<name<<endl;
        cout<<marks<<endl;
        student_details[i].first = name;
        student_details[i].second = marks;
    }

    sort(student_details,student_details+n,compare);
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<" "<<student_details[i].first<<endl;
    }
	return 0;
}

