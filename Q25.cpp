#include<bits/stdc++.h>
using namespace std;
int partyHalls(vector<int> s,vector<int> e)
{
    sort(s.begin(),s.end());
    sort(e.begin(),e.end());
    int count=0,ans=0,i=0,j=0;
    while(i<s.size() && j<e.size())
    {
        if(s[i]<e[j])
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }
        ans=max(count,ans);
        
    }
    return ans;
}
int main()
{
    vector<int> s,e;
    int n,start,end;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>start>>end;
        s.push_back(start);
        e.push_back(end);
    }
    int answer = partyHalls(s,e);
    cout<<"Number of halls required is: "<<answer;
    return 0;
}