class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(),res=0;
        vector<vector<int>>sum(m+1,vector<int>(n+1,0));
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                sum[i][j] = sum[i-1][j] + sum[i][j-1] + matrix[i-1][j-1] - sum[i-1][j-1];
            }
        }
        for(int k=1;k<=min(m,n);k++){
            for(int i=0;i<m+1-k;i++){
                for(int j=0;j<n+1-k;j++){
                    int num = sum[i+k][j+k] - sum[i+k][j] - sum[i][j+k] + sum[i][j];
                    if(num==k*k) res++;
                }
            }
        }
        return res;
    }
};