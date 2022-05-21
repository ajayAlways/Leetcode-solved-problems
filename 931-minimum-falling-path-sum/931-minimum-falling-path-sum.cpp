class Solution {
private:
    int t[101][101];
public:
    int solve(vector<vector<int>>& matrix, int i, int j){
        if(j<0 || j>matrix.size()-1) return INT_MAX;
        if(i==0) return t[i][j]=matrix[i][j];
        
        if(t[i][j]!=INT_MAX) return t[i][j];
        
        int dl,dr,d;
        
        dl = solve(matrix,i-1,j-1);
        d = solve(matrix,i-1,j);
        dr = solve(matrix,i-1,j+1);
        
        return t[i][j] = min(min(dl,dr),d)+matrix[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                t[i][j]=INT_MAX;
            }
        }
        for(int i=0;i<matrix.size();i++){
            ans = min(ans,solve(matrix,matrix.size()-1,i));
        }
        return ans;
    }
};