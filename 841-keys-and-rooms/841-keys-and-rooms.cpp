class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<int>& vis,int node){
        vis[node] = 1;
        for(auto& i:rooms[node]){
            if(!vis[i]) dfs(rooms, vis, i);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,0);
        dfs(rooms,vis,0);
        for(auto& i:vis){
            if(i==0) return false;
        }
        return true;
    }
};