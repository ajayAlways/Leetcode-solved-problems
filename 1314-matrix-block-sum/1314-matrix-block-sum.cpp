class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>>res(mat.size(),vector<int>(mat[0].size(),0));
        int m = mat.size(),n=mat[0].size();
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                int sum=0,range1=min(m,i+k+1),range2=min(n,j+k+1);
                for(int l=max(0,i-k);l<range1;l++){
                    for(int p=max(0,j-k);p<range2;p++){
                        sum+=mat[l][p];
                    }
                }
                res[i][j] = sum;
            }
        }
        return res;
    }
};