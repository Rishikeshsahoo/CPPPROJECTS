#include<bits/stdc++.h>
using namespace std;
vector<string> findTheRanges(vector<int> nums)
{
    int i=0;
    string temp="";
    int num;
    vector<string> ans;
    while(i<nums.size())
    {
        num=nums[i];
        temp+=to_string(nums[i]);
        while((i+1)<nums.size() && nums[i+1]==nums[i]+1)
        i++;

        if(nums[i]!=num)
        {
        temp+="->";
        temp+=to_string(nums[i]);
        }
        ans.push_back(temp);
        temp="";
        i++;
    }
    return ans;
}
int main()
{
    vector<int> v={0,1,2,4,5,7};
    vector<string> ans=findTheRanges(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }

    return 0;
}