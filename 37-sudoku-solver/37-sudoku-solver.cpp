class Solution {
public:
    bool isValid(vector<vector<char>>&board, int r, int c, char num){
    int n = board.size();
    for(int i=0;i<9;i++){
        if(board[r][i]==num) return false;
    }
    for(int i=0;i<9;i++){
        if(board[i][c]==num) return false;
    }
    r = r-r%3;
    c = c - c%3;
    for(int i=r;i<(r+3);i++){
        for(int j=c;j<(c+3);j++){
            if(board[i][j]==num) return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>>&board, int i, int j){
    if(j==9) return true;
    if(i==9) return solve(board,0,j+1);
    if(board[i][j]!='.') return solve(board,i+1,j);
    for(char num='1';num<='9';num++){
        if(isValid(board,i,j,num)){
            board[i][j] = num;
            if(solve(board,i+1,j)) return true;
            board[i][j] = '.';
        }  
    }
    return false;
}
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};