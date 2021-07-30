#include<bits/stdc++.h>
using namespace std;


class SolOptimal{
    public:
        void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &lowerDiagnal, vector<int> &upperDiagnal, int n){
            if(col == n){
                ans.push_back(board);
                return;
            }

            for(int row=0;row<n;row++){
                if(leftRow[row]==0 && lowerDiagnal[row+col]==0 && upperDiagnal[n-1 + col-row]==0){
                    board[row][col]= 'Q';
                    leftRow[row]= 1;
                    lowerDiagnal[row+col]=1;
                    upperDiagnal[n-1 + col-row]=1;
                    solve(col+1,board,ans,leftRow,lowerDiagnal,upperDiagnal,n);
                    board[row][col] = '.';
                    leftRow[row] = 0;
                    lowerDiagnal[row + col] = 0;
                    upperDiagnal[n - 1 + col - row] = 0;
                }
            }
        }
        vector<vector<string>> solveNQueens(int n)
        {
            vector<vector<string>> ans;
            vector<string> board(n);
            string s(n, '.');
            for (int i = 0; i < n; i++)
            {
                board[i] = s;
            }
            vector<int> leftRow(n,0), lowerDiagnal(2*n-1,0), upperDiagnal(2*n-1,0);
            solve(0, board, ans,leftRow,lowerDiagnal,upperDiagnal,n);
            return ans;
        }
};
class SolBrute
{
    public:
        bool isSafe(int row,int col,vector<string> &board,int n){
            int duprow= row;
            int dupcol= col;

            while(row>=0 && col>=0){
                if(board[row][col]=='Q')
                    return false;
                row--;
                col--;
            }

            row= duprow;
            col= dupcol;
            while(col>=0){
                if(board[row][col]=='Q')
                    return false;
                col--;
            }

            row= duprow;
            col= dupcol;
            while(row<n && col>=0){
                if (board[row][col] == 'Q')
                    return false;
                row++;
                col--;
            }
            return true;
        }
        void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
            if(col == n){
                ans.push_back(board);
                return;
            }
            for(int row=0;row<n;row++){
                if(isSafe(row,col,board,n)){
                    board[row][col]= 'Q';
                    solve(col+1,board,ans,n);
                    board[row][col]='.';
                }
            }
        }
        vector<vector<string>> solveNQueens(int n)
        {
            vector<vector<string>> ans;
            vector<string> board(n);
            string s(n,'.');
            for(int i=0;i<n;i++){
                board[i]= s;
            }
            solve(0,board,ans,n);
            return ans;
        }
};

int main()
{
    int n;
    cin>>n;
    SolBrute s1;
    SolOptimal s2;
    vector<vector<string>> res= s2.solveNQueens(n);
    cout<<"{";
    for (auto const &string_vec : res){
        cout<<"[ ";
        for (auto const &s : string_vec){
            cout<<"'"<< s <<"' "; 
        }
        cout<<"  ]\n";
    }
    cout<<"}";
    return 0;
}