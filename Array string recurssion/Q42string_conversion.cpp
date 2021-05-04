#include<bits/stdc++.h>
using namespace std;
bool stringConversion(string s,string t)
{
    if(s==t)
    return false;
    string s1,s2;
    if(s.size()>=t.size())
    {
        s2=s;
        s1=t;
    }
    else if(s.size()<t.size())
    {
        s2=t;
        s1=s;
    }
    if(s1.size()!=s2.size())
    {
        int count=0;
        for(int i=0,j=0;i<s1.size() && j<s2.size();)
        {
            if(s1[i]==s2[j])
            {
                count++;
                i++;
                j++;
            }
            else
            j++;
        }
        
        if(s2.size()-count==1)
        return true;
        return false;
    }
    else if(s1.size()==s2.size())
    {
        int count=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==s2[i])
            count++;
        }
        cout<<count<<endl;
        if(s2.size()-count==1)
        return true;
        return false;
    }
    

}
int main()
{
    string s1="abcd",s2="abed";
    cout<<stringConversion(s1,s2);
    return 0;
}