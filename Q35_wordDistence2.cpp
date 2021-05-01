#include<bits/stdc++.h>
using namespace std;
int wordDistence2(vector<string> s,string s1,string s2)
{
    if(s1==s2)
    {
        int p=-1,ans=INT_MAX;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==s1 && p==-1)
            p=i;
            else if(s[i]==s1 && p!=-1)
            ans=min(ans,abs(i-p));
        }
        return ans;
    }
    else
    {
        int a1=-1,a2=-1,ans=INT_MAX;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==s1)
            {
                a1=i;
            }
            else if(s[i]==s2)
            {
                a2=i;
            }
            if(a1!=-1 && a2!=-1)
            {
                ans=min(ans,abs(a1-a2));
            }
        }
        return ans;
    }

}
int main()
{
    int n;
    string str;
    vector<string> s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        s.push_back(str);
    }
    cout<<"answer is: "<<wordDistence2(s,"Rishikesh","Rishikesh");
    return 0;
}