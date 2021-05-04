#include<bits/stdc++.h>
using namespace std;
int comparingVersions(string s1,string s2)
{
    int i=0,j=0;
    int n1=s1.size();
    int n2=s2.size();
    while(i<n1 || j<n2)
    {
        int num1=0,num2=0,num;
        while(i<n1 && s1[i]!='.')
        {
            num=s1[i]-'0';
            num1=num1*10+num;
            i++;
        }
        while(j<n2 && s1[j]!='.')
        {
            num=s2[j]-'0';
            num2=num2*10+num;
            j++;
        }
        if(num1>num2) return 1;
        if(num2>num1) return -1;
        else
        {
            i++;
            j++;
        }
    }
    return 0;
}
int main()
{
    string s1="7.35.0002";
    string s2="7.35.3";
    cout<<comparingVersions(s1,s2);
    return 0;
}