class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), k=0;
        for(int i=0;i<n;i++){
            if(k==0 || nums[k-1]!=nums[i]){
                nums[k] = nums[i];
                k++;
            }
            
        }
        
        return k;
    }
};