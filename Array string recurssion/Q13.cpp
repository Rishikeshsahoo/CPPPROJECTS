#include<bits/stdc++.h>
using namespace std;
int wordDistence1(vector<string> s,string s1,string s2)
{
    int a1=-1,a2=-1,res=INT_MAX;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==s1)
        a1=i;
        else if(s[i]==s2)
        a2=i;
        if(a1!=-1 && a2!=-1)
        {
            res=min(res,abs(a2-a1));
        }

    }
    return res;
}
int main()
{
    int n;
    string k;
    vector<string> s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        s.push_back(k);
    }

    int ans=wordDistence1(s,"Rishikesh","sahoo");
    cout<<endl<<ans;


}