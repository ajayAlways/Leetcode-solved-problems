class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0,i=0,j=height.size()-1;
        while(i<j){
            int mini = min(height[i],height[j]);
            ans = max(ans, mini*(j-i));
            while(height[i]<=mini && i<j) i++;
            while(height[j]<=mini && i<j) j--;
        }
        return ans;
    }
};