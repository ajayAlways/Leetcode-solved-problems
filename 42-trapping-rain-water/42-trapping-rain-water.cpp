class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>leftMax(height.size(),0);
        vector<int>rightMax(height.size(),0);
        int maxi = 0,trappedArea=0;
        for(int i=0;i<height.size();i++){
            maxi = max(maxi,height[i]);
            leftMax[i]=maxi;
        }
        maxi=0;
        for(int i=height.size()-1;i>=0;i--){
             maxi = max(maxi,height[i]);
             rightMax[i]=maxi;
        }
        for(int i=0;i<height.size();i++){
            trappedArea+= min(leftMax[i],rightMax[i])-height[i];
        }
        return trappedArea;
    }
};