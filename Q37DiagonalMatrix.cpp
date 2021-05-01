#include<bits/stdc++.h>
using namespace std;
vector<int> diagonalMatrix(vector<vector<int>> v)
{
    int d=1;
    int row=0;
    int col=0;
    int n=v.size();
    int m=v[0].size();
    vector<int> result(m*n,-1);
    for(int i=0;i<result.size();i++)
    {
        result[i]=v[row][col];
        if(d==1)
        {
            if(col==m-1)
            {
                d=-1;
                row++;
            }
            else if(row==0)
            {
                d=-1;
                col++;
            }
            
            else
            {
                col++;
                row--;
            }
        }
        else
        {
            if(row==n-1)
            {
                d=1;
                col++;
            }
            else if(col==0)
            {
                d=1;
                row++;
            }
            
            else
            {
                row++;
                col--;
            }
        }
    }

    cout<<result.size()<<endl;
    return result;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++)
    {
        vector<int> k(n,-1);
        for(int j=0;j<n;j++)
        {
            cin>>k[j];
        }
        v.push_back(k);
    }
    cout<<endl;
    vector<int> ans;
    ans=diagonalMatrix(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}