#include<bits/stdc++.h>
using namespace std;
bool validSudoku(vector<vector<char>> board)
{
    map<int,map<int,int>> R;
    map<int,map<int,int>> C;
    map<int,map<int,int>> B;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]!='0')
            {
                int num=board[i][j]-'0';
                if(R[i][num]==1){
                cout<<"1. "<<j<<" "<<num<<endl;
                return false;
                }
                if(C[j][num]==1)
                {cout<<"2. "<<j<<" "<<num<<endl;
                return false;
                }

                int box_number=(i/3)*3 + j/3;
                if(B[box_number][num]==1)
                {
                cout<<"3. "<<box_number<<" "<<num<<endl;
                return false;}
                
                R[i][num]=1;
                C[j][num]=1;
                B[box_number][num]=1;
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<char>> board;
    for(int i=0;i<9;i++)
    {
        vector<char> temp(9,0);
        for(int j=0;j<9;j++)
        {
            cin>>temp[j];
        }
        board.push_back(temp);
    }
    cout<<endl;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<validSudoku(board);
    return 0;
}

// 5 3 0 7 0 0 0 0 0
// 6 0 0 1 8 2 0 0 0
// 0 8 7 0 0 0 0 6 0
// 8 0 0 0 6 0 0 0 3
// 4 0 0 8 0 3 0 0 1
// 7 0 0 0 2 0 0 0 6
// 0 6 0 0 0 0 2 8 0
// 0 0 0 4 1 7 0 0 5
// 0 0 0 0 5 0 0 0 9