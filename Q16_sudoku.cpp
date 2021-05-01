#include<bits/stdc++.h>
using namespace std;
bool isSafe(int mat[9][9],int i,int j,int num)
{
    for(int k=0;k<9;k++)
    {
        if(mat[i][k]==num || mat[k][j]==num)
        return false;
    }
    int row=(i/3)*3,col=(j/3)*3;
    for(int p=row;p<row+3;p++)
    {
        for(int q=col;q<col+3;q++)
        {
            if(mat[p][q]==num)
            return false;
        }
    }
    return true;

}
bool solve(int mat[9][9],int i,int j)
{
    if(j==9)
    return solve(mat,i+1,0);
    if(i==9)
    return true;
    if(mat[i][j]==0){
    for(int k=1;k<=9;k++)
    {
        
        if(isSafe(mat,i,j,k))
        {
            mat[i][j]=k;
            bool canSolve=solve(mat,i,j+1);
            if(canSolve) return true;
            mat[i][j]=0;
        }

    }
    return false;
    }
    else return solve(mat,i,j+1);
}
int main()
{
    int n;
    cin>>n;
    int mat[9][9];
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>mat[i][j];
        }
        
    }
    
    bool answer=solve(mat,0,0);
    cout<<answer<<endl;
    if(answer)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<mat[i][j]<<" ";
            }
        cout<<endl;
        
        }
    }

}