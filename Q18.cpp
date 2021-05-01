#include<bits/stdc++.h>
using namespace std;
int maxLengthSubstring(string str)
{
    string modstr;
    for(int i=0;i<str.length()*2+1;i++)
    {
        if(i%2==0)
        modstr+="#";
        else modstr+=str[i/2];
    }
    int r=0;//starting with right limit as 0
    int c=0;//starting with center as 0
    int input[str.length()*2+1]={0};
    for(int x=1;x<str.length()*2+1;x++)
    {
        int mirr=2*c-x;
        if(x<r)
        input[x]=min(r-x,input[x]);
        while(x+input[x]+1<=modstr.length() && x-input[x]-1>=0 && modstr[x-input[x]-1]==modstr[x+input[x]+1])
        input[x]++;
    }
    int maxint=INT_MIN,i1;
    for(int i=0;i<str.length()*2+1;i++)
    {
        if(maxint<input[i])
        {
            i1=i;
            maxint=input[i];
        }
    }
    if(i1%2!=0)
    {
        for(int i=(i1/2)-(maxint/2);i<=(i1/2)+(maxint/2);i++)
        cout<<str[i];
    }
    else
    {

    }
}
int main()
{
    string s="ijabacabacaba";
    // cin>>s;
    int k=maxLengthSubstring(s);

    return 0;
}