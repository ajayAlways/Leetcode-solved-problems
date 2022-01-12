class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0,i=0,j=height.size()-1;
        while(i<j){
            int mini = min(height[i],height[j])*(j-i);
            ans = max(ans, mini);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return ans;
    }
};