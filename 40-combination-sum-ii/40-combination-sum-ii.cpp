class Solution {
public:
    void findCombs(vector<int>&nums, vector<vector<int>>&res,vector<int>&curComb,int target,int curSum,int pos){
    if(curSum==target){
        res.push_back(curComb);
        return;
    }
    if(curSum>target || pos>=nums.size()) return;
    for(int i=pos;i<nums.size();i++){
        if(i>pos && nums[i]==nums[i-1]) continue;
        if(curSum+nums[i]<=target){
            curComb.push_back(nums[i]);
            findCombs(nums,res,curComb,target,curSum+nums[i],i+1);
            curComb.pop_back();
        }
    }
}
    vector<vector<int>> combinationSum2(vector<int>& A, int B) {
        int n = A.size();
        vector<vector<int>>res;
        vector<int>curComb;
        sort(A.begin(),A.end());
        findCombs(A,res,curComb,B,0,0);
        sort(res.begin(),res.end());

        return res;
    }
};