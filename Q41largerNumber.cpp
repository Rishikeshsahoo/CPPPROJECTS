#include<bits/stdc++.h>
using namespace std;

int make_num(vector<int> v,int s)
{
    int num=0;
    for(int i=s;i<v.size();i++)
    {
        num=(num*10)+v[i];
    }
    return num;

}
int largerNumber(int num)
{
    
    vector<int> v(9,11);
    int s=0;
    int j=9-1;
    while(num>0)
    {
        if(j<0)
        return -1;
        v[j--]=num%10;
        num/=10;
    }
    s=j+1;
    int e=8;
    while(e>s)
    {
        if(v[e]>v[e-1])
        break;
        e--;
    }
    if(e==s)
    return -1;
    int pos1=e-1;
    int pos2=e;
    while(e<8)
    {
        if(v[e]>v[pos1] && v[e]<v[pos2])
        pos2=e;
        e++;
    }
    swap(v[pos1],v[pos2]);
    sort(v.begin()+pos1+1,v.end());
    return make_num(v,s);
}

int main()
{
    int n=1234;
    cout<<largerNumber(n);
    return 0;
}