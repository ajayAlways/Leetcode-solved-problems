class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size(),ans=INT_MAX,res=0;
        for(int i=0;i<n-2;i++){
            int begin=i+1,end=n-1,k = target - nums[i];
            while(begin<end){
                int sum=nums[begin]+nums[end];
                if(k<sum) end--;
                else if(k>sum) begin++;
                else{
                    return target;
                }
                
                int diff = sum+nums[i] - target;
                if(abs(diff)<abs(ans)){
                    ans = diff;
                    res = sum+nums[i];
                }
            }
        }
        return res;
    }
};