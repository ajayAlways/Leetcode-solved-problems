class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(),rightMaxi=-1,leftMaxi=-1,res=0;
        vector<int>rightMax(n,-1);
        for(int i=n-1;i>=0;i--){
            rightMax[i] = rightMaxi;
            rightMaxi = max(rightMaxi,height[i]);
        }
        for(int i=0;i<n;i++){
            if(leftMaxi!=-1 && rightMax[i]!=-1){
                res+=max(min(leftMaxi,rightMax[i])-height[i],0); 
            }
            leftMaxi = max(leftMaxi,height[i]);
        }
        
        return res;
    }
};