class Solution {
public:
    void dfs(vector<vector<int>>& graph, int node,vector<vector<int>>& res, vector<int>& path){
        path.push_back(node);
        if(node == graph.size()-1) res.push_back(path);
        else{
            for(auto& i:graph[node]){
                dfs(graph, i, res, path);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        vector<int>path;
        path.push_back(0);
        for(auto& i:graph[0]){
            dfs(graph,i,res,path);
        }
        return res;
    }
};