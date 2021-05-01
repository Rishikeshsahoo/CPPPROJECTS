#include<bits/stdc++.h>
using namespace std;
vector<string> keypadarr={"","abc","def"};
void keypad(string s,string ans)
{
    if(s=="")
    {
        cout<<ans<<" ";
        return;
    }
    char ch=s[0];
    string code=keypadarr[ch-'0'];

    for(int i=0;i<code.size();i++)
    {
        keypad(s.substr(1),ans+code[i]);
    }
}
int main()
{
    keypad("12","");
    return 0;
}