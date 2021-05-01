#include<bits/stdc++.h>
using namespace std;
bool comparator(int i,int j)
{
    string s1=to_string(i);
    string s2=to_string(j);

    return (s1+s2)>(s2+s1);

}
string largestNumber(vector<int> &v)
{
    sort(v.begin(),v.end(),comparator);
    string s;
    for(int i=0;i<v.size();i++)
    {
        s+=to_string(v[i]);
    }
    return s;

}
int main()
{
    int n=0,t;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        v.push_back(t);
    }
    string s=largestNumber(v);
    cout<<endl<<s;
    return 0;
}