class Solution {
public:
    bool countNeighbors(vector<vector<int>>grid,int i, int j){
        int dx[8] = {0,1,1,1,0,-1,-1,-1};
        int dy[8] = {-1,-1,0,1,1,1,0,-1};
        if(grid[i][j]==0){
            int count=0;
            for(int k=0;k<8;k++){
                if(i+dx[k]>=0 && i+dx[k]<grid.size() && j+dy[k]>=0 && j+dy[k]<grid[0].size() && (grid[i+dx[k]][j+dy[k]]==1 || grid[i+dx[k]][j+dy[k]]==-1)) count++;
            } 
            return count==3;
        }
        else{
            int count=0;
            for(int k=0;k<8;k++){
                if(i+dx[k]>=0 && i+dx[k]<grid.size() && j+dy[k]>=0 && j+dy[k]<grid[0].size() && (grid[i+dx[k]][j+dy[k]]==1 || grid[i+dx[k]][j+dy[k]]==-1)) count++;
            } 
            return count<2 || count>3;
        }
        return true;
    }
    void gameOfLife(vector<vector<int>>& board) {
        // vector<pair<int,int>>pos;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(countNeighbors(board,i,j)){
                    if(board[i][j]==0) board[i][j]=2;
                    else board[i][j]=-1;
                }
            }
        }
        // for(auto& i:pos){
        //     board[i.first][i.second] = !board[i.first][i.second];
        // }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==1 || board[i][j]==2) board[i][j]=1;
                else board[i][j]=0;
            }
        }
    }
};