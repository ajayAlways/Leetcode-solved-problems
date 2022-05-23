class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        //  Time - O(N), Space - O(N)
        // int ans=INT_MIN,leftMax=INT_MIN;
        // stack<int>st;
        // for(int i=values.size()-1;i>0;i--){
        //     leftMax = max(leftMax,values[i]-i);
        //     st.push(leftMax);
        // }
        // for(int i=0;i<values.size()-1;i++){
        //     ans=max(ans,values[i]+i+st.top());
        //     st.pop();
        // }
        // return ans;
        
        // Time - O(N) & Space - O(1) 
        int res=0,leftMax=0;
        for(int i=0;i<values.size();i++){
            res = max(res,leftMax+values[i]-i);
            leftMax = max(leftMax,values[i]+i);
        }
        return res;
    }
};