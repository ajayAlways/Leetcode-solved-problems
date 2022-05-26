class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res=0;
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1) adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>>q;
        q.push({headID,0});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int node = q.front().first;
                int time = q.front().second;
                q.pop();
                int dur = informTime[node]+time;
                res = max(res,dur);
                if(informTime[node]!=0){
                    for(auto& j:adj[node]) q.push({j,dur});
                }
            }
        }
        return res;
    }
};