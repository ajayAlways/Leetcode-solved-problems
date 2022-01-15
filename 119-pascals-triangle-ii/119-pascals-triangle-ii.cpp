class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // vector<vector<int> >ans;
        vector<int>ans(rowIndex+1,1);
        // ans.push_back({1});
        for(int i=2;i<=rowIndex;i++){
            // ans.push_back({});
            for(int j=i-1;j>0;j--){
                ans[j] = ans[j]+ans[j-1];
            }
        }
        return ans;
    }
};