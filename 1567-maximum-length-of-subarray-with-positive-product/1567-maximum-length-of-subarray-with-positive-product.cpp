class Solution {
public:
    int solve(vector<int>& nums, int s,int e){
        int firstNeg=-1,lastNeg=-1,countNeg=0;
        for(int i=s;i<=e;i++){
            if(nums[i]<0){
                firstNeg=firstNeg<0 ? i:firstNeg;
                lastNeg = i;
                countNeg++;
            }
        }
        if(countNeg==0) return e-s+1;
        if(countNeg%2==0) return e-s+1;
        else return max(e-firstNeg,lastNeg-s);
        
    }
    int getMaxLen(vector<int>& nums) {
        int s=-1,e=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) s = s<0 ? i:s;
            if(i>0 && nums[i]==0){
                e=i-1;
                if(s!=-1) ans = max(ans,solve(nums,s,e));
                while(i<nums.size() && nums[i]==0) i++;
                s=i;
            }
            else if(i==nums.size()-1){
                ans = max(ans,solve(nums,s,i));
            }
        }
        return ans;
    }
};