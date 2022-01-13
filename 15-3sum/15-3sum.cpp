class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) return {};
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int begin = i+1,target=-1*nums[i],end=n-1,sum=0;
            
            if(target < 0) break;
            while(begin<end){
                sum=nums[begin]+nums[end];
                if(sum>target) end--;
                else if(sum<target) begin++;
                else{
                    vector<int>triplet={nums[i],nums[begin],nums[end]};
                    ans.push_back(triplet);
                    
                    while(begin<end && nums[begin]==triplet[1]) begin++;
                    while(begin<end && nums[end]==triplet[2]) end--;
                }
            }
        }
        return ans;
        
    }
};