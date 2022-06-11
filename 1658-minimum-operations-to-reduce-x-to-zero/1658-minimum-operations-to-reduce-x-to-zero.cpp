class Solution {
private:
    unordered_map<string,int>dp;
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(),presum=0,target,sum=0,j=0,res=-1;
        for(auto& i:nums) sum+=i;
        target = sum - x;
        if(target<0) return -1;
        if(target==0) return n;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            while(presum>target){
                presum-=nums[j];
                j++;
            }
            if(presum==target) res = max(res,i-j+1);
        }
        return res!=-1 ? n-res:-1;
    }
};