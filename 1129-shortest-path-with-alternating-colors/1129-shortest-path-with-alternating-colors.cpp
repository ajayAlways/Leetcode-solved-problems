class Solution {
public:
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
        queue<pair<int,int>>q;
        vector<vector<int>>dist(n,vector<int>(2,-1));
        for(auto& i:redEdges) adj[i[0]].push_back({i[1],0});
        for(auto& i:blueEdges) adj[i[0]].push_back({i[1],1});
        dist[0] = {0,0};
        q.push({0,0});
        q.push({0,1});
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto& i:adj[node.first]){
                if(dist[i.first][i.second]==-1 && node.second!=i.second){
                    dist[i.first][i.second] = dist[node.first][node.second] + 1;
                    q.push(i);
                }
            }
        }
        vector<int>res;
        for(auto& i:dist){
            sort(i.begin(),i.end());
            if(i[0]!=-1) res.push_back(i[0]);
            else res.push_back(i[1]);
        }
        return res;
        
    }
};