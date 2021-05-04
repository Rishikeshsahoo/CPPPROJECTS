#include<bits/stdc++.h>
using namespace std;
string maxPreffix(vector<string> v)
{
    string ans=v[0];
    for(int i=1;i<v.size();i++)
    {
        string temp="";
        for(int j=0;j<min(ans.size(),v[i].size());j++)
        {
            if(ans[j]==v[i][j])
            temp+=ans[j];
            else break;
        }
        ans=temp;
    }
    return ans;
}
int main()
{
    vector<string> v;
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        v.push_back(s);
    }
    string str=maxPreffix(v);
    cout<<"\nanswer is: "<<str;
    return 0;
}