#include<bits/stdc++.h>
using namespace std;
bool checkMeeting(vector<vector<int>> &mainvector)
{
    sort(mainvector.begin(),mainvector.end());
    for(int i=1;i<mainvector.size();i++)
    {
        if(mainvector[i][0]<mainvector[i-1][1])
        return false;
    }
    return true;
}
int main()
{   
    int n,s,e;
    vector<vector<int>> mainvector;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s>>e;
        vector<int> temp;
        temp.push_back(s);
        temp.push_back(e);
        mainvector.push_back(temp);
    }
    cout<<endl<<checkMeeting(mainvector);

    return 0;
}