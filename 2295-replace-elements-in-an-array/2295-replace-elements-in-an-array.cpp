class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int>m;
        int n = nums.size();
        for(int i=0;i<n;i++) m[nums[i]] = i;
        for(auto& i:operations){
            int pos = m[i[0]];
            nums[pos] = i[1];
            m.erase(i[0]);
            m[i[1]] = pos;
        }
        return nums;
    }
};