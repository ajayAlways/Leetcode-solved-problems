class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int,int>m;
        int count=0,majarity=nums[0];
        for(auto i:nums){
            // m[i]++;
            // if(m[i]>(nums.size()/2)) return i;
            if(count==0){
                majarity = i;
            }
            count+=(i==majarity)?1:-1;
        }
        return majarity;
    }
};