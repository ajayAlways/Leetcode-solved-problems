class Solution {
public:
    bool isValid(vector<vector<char>>&board, int r, int c, char num){
        int n = board.size();
        for(int i=0;i<9;i++){
            if(i!=c && board[r][i]==num) return false;
        }
        for(int i=0;i<9;i++){
            if(i!=r && board[i][c]==num) return false;
        }
        int nr = r-r%3;
        int nc = c - c%3;
        for(int i=nr;i<(nr+3);i++){
            for(int j=nc;j<(nc+3);j++){
                if(i!=r && j!=c && board[i][j]==num) return false;
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.' && !isValid(board,i,j,board[i][j])) return false;
            }
        }
        
        return true;
    }
};