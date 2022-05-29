class Solution {
private:
    int t[201][201];
public:
    int solve(vector<vector<int>>& triangle, int i, int j){
        if(j<0 || j>=triangle[i].size()) return INT_MAX;
        if(i==triangle.size()-1) return t[i][j] = triangle[i][j];
        if(t[i][j]!=-1) return t[i][j];
        int d = triangle[i][j] + solve(triangle,i+1,j);
        int dr = triangle[i][j] + solve(triangle, i+1, j+1);
        return t[i][j] = min(d,dr);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(t,-1,sizeof t);
        return solve(triangle,0,0);
    }
};