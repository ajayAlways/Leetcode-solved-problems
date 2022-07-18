class Solution {
public:
    
    void findCombs(vector<int>&nums, vector<vector<int>>&res,vector<int>&curComb,int target,int curSum,int pos){
        if(curSum==target){
            res.push_back(curComb);
            return;
        }
        if(curSum>target || pos>=nums.size()) return;
        for(int i=pos;i<nums.size();i++){
            if(curSum+nums[i]<=target){
                curComb.push_back(nums[i]);
                findCombs(nums,res,curComb,target,curSum+nums[i],i);
                curComb.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>curComb;
        unordered_set<int>st(candidates.begin(),candidates.end());
        candidates.clear();
        for(auto& i:st) candidates.push_back(i);
        // sort(A.begin(),A.end());
        findCombs(candidates,res,curComb,target,0,0);
        // sort(res.begin(),res.end());

        return res;
    }
};