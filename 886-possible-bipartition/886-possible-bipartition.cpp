class Solution {
public:
    bool bfs(vector<vector<int>>& adj, int node,vector<int>& vis,int color){
        queue<pair<int,int>>q;
        q.push({node,color});
        while(!q.empty()){
            auto i = q.front();
            q.pop();
            for(auto& j:adj[i.first]){
                if(vis[j]!=-1 && vis[j]==i.second) return false;
                if(vis[j]==-1){
                    q.push({j,!i.second});
                    vis[j] = !i.second;
                }
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>>& adj, int node,vector<int>& vis,int color){
        vis[node] = color;
        for(auto& i:adj[node]){
            if(vis[i]!=-1 && vis[i]==color) return false;
            if(vis[i]==-1){
                if(!dfs(adj,i,vis,!color)) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        vector<int>vis(n+1,-1);
        for(auto& i:dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==-1){
                if(!bfs(adj,i,vis,0)) return false;
            }
        }
        return true;
    }
};