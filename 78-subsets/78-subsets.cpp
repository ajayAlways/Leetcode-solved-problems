class Solution {
public:
    void findSubsets(vector<int>& nums,vector<vector<int>>&res,vector<int> &curSubSet,int pos){
        if(pos==nums.size()){
            res.push_back(curSubSet);
            return;
        }
        findSubsets(nums,res,curSubSet,pos+1);
        curSubSet.push_back(nums[pos]);
        findSubsets(nums,res,curSubSet,pos+1);
        curSubSet.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curSubSet;
        // sort(A.begin(),A.end());
        findSubsets(nums,res,curSubSet,0);
        // sort(res.begin(),res.end());
        return res;
    }
};