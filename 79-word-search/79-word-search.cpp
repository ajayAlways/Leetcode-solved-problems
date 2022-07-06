class Solution {
public:
//     bool bfs(vector<vector<char>>& board, string word){
//         int m = board.size(), n = board[0].size();
//         queue<pair<int,int>>q;
//         vector<vector<int>>visited(m,vector<int>(n,0));
//         q.push({0,0});
//         visited[0][0] = 1;
//         while(!q.empty()){
//             int x = q.top().first, y = q.top().second;
//             q.pop();
            
//         }
//     }
    bool dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int i, int j, string& word, int pos){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || vis[i][j]==1 || board[i][j]!=word[pos]) return false;
        vis[i][j] = 1;
        if(pos==word.length()-1) return true;
        bool l = dfs(board,vis,i,j+1,word,pos+1);
        bool d = dfs(board,vis,i+1,j,word,pos+1);
        bool r = dfs(board,vis,i,j-1,word,pos+1);
        bool u = dfs(board,vis,i-1,j,word,pos+1);
        vis[i][j] = 0;
        return l || d || r || u;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,vis,i,j,word,0)) return true;
                    // else vis = vector<vector<int>>(m,vector<int>(n,0));
                }
            }
        }
        
        return false;
    }
};