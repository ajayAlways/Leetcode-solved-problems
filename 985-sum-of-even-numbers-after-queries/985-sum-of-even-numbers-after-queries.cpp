class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>res;
        int evenSum=0;
        for(auto& i:nums){
            if(i%2==0) evenSum+=i;
        }
        for(auto& i:queries){
            if((nums[i[1]]+i[0])%2==0){
                if(nums[i[1]]%2==0){
                    evenSum+=i[0];
                }
                else{
                    evenSum+=nums[i[1]]+i[0];
                }
            }
            else{
                if(nums[i[1]]%2==0) evenSum-=nums[i[1]];
            }
            res.push_back(evenSum);
            nums[i[1]]+=i[0];
        }
        
        return res;
    }
};