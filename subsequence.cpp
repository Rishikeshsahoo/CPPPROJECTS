#include<bits/stdc++.h>
using namespace std;
void subsequence(string s,string ans)
{
    if(s=="")
    {
        cout<<ans<<" ";
        return;
    }
    int asc=s[0];
    subsequence(s.substr(1),ans);
    subsequence(s.substr(1),ans+s[0]);
    subsequence(s.substr(1),ans+to_string(asc));
}
int main()
{
    string s;
    cin>>s;
    subsequence(s,"");
    return 0;
}