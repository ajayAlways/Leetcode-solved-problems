class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        vector<int>inDegree(n,0);
        queue<int>q;
        vector<int>res;
        for(auto& i:prerequisites){
            adj[i[1]].push_back(i[0]);
            inDegree[i[0]]++;
        }
        for(int i=0;i<n;i++){
            if(inDegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto& i:adj[node]){
                inDegree[i]--;
                if(inDegree[i]==0) q.push(i);
            }
        }
        if(res.size()==n) return res;
        return {};
    }
};