class Solution {
public:
    bool solve(vector<int>& arr, int start, unordered_map<int,int>&vis){
        if(start<0 || start>=arr.size()) return false;
        vis[start]++;
        if(vis[start]>2) return false;
        else{
            if(arr[start]==0) return true;
            return solve(arr,start+arr[start],vis) || solve(arr,start-arr[start],vis);
        }
        
    }
    bool canReach(vector<int>& arr, int start) {
        unordered_map<int,int>vis;
        return solve(arr,start,vis);
    }
};