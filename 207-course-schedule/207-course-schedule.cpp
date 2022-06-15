class Solution {
public:
    bool checkCycle(vector<vector<int>>& adj, vector<int>& vis,vector<int>& dfsVis, int node){  
        if(dfsVis[node]) return true;
        if(vis[node]) return false;
        dfsVis[node] = vis[node] = 1;
        for(auto& i:adj[node]){
            if(checkCycle(adj,vis,dfsVis,i)) return true;
        }
        dfsVis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        vector<int>dfsVis(n,0);
        for(auto& i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(checkCycle(adj,vis,dfsVis,i)) return false;
            }
        }
        return true;
    }
};