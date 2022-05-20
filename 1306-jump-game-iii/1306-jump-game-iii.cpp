class Solution {
private:
    bool t[50001];
public:
    bool solve(vector<int>& arr, int start, unordered_map<int,int>&vis){
        if(start<0 || start>=arr.size()) return false;
        vis[start]++;
        if(vis[start]>2) return false;
        if(t[start]==true) return true;
        else{
            if(arr[start]==0) return t[start] = true;
            return t[start] = solve(arr,start+arr[start],vis) || solve(arr,start-arr[start],vis);
        }
        
    }
    bool canReach(vector<int>& arr, int start) {
        unordered_map<int,int>vis;
        memset(t,false,sizeof(t));
        return solve(arr,start,vis);
    }
};