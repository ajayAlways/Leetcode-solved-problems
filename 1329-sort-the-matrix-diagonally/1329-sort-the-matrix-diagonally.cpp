class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>Map;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                Map[i-j].push(matrix[i][j]);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = Map[i-j].top();
                Map[i-j].pop();
            }
        }
        
        return matrix;
    }
};