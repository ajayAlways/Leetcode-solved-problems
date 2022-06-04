class Solution {
public:
    bool isSafe(vector<string>& board, int i, int j){
        int row = i,column = j;
        for(int k=i;k>=0;k--){
            if(board[k][j]=='Q') return false;
        }
        while(row>=0 && column>=0){
            if(board[row][column]=='Q') return false;
            row--;
            column--;
        }
        row = i, column = j;
        while(row>=0 && column<board[0].size()){
            if(board[row][column]=='Q') return false;
            row--;
            column++;
        }
        return true;
    }
    void solve(vector<vector<string>>& res,vector<string>& board, int row,int n){
        if(row>=n){
            res.push_back(board);
            return;
        }
        
        for(int i=0;i<board[row].size();i++){
            if(isSafe(board,row,i)){
                board[row][i] = 'Q';
                
                solve(res,board,row+1,n);
                
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n);
        string row(n,'.');
        for(int i=0;i<n;i++) board[i] = row;
        solve(res,board,0,n);
        return res;
        
    }
};