class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r1=0,r2=matrix.size()-1,c1=0,c2=matrix[0].size()-1;
        vector<int>res;
        while(r1<=r2 && c1<=c2){
            if(r1<=r2){
                for(int i=c1;i<=c2;i++){
                res.push_back(matrix[r1][i]);
                }
                r1++;
            }
            if(c1<=c2){
                for(int i=r1;i<=r2;i++){
                    res.push_back(matrix[i][c2]);
                }
                c2--;
            }
            if(r1<=r2){
                for(int i=c2;i>=c1;i--){
                    res.push_back(matrix[r2][i]);
                }
                r2--;
            }
            if(c1<=c2){
                for(int i=r2;i>=r1;i--){
                    res.push_back(matrix[i][c1]);
                }
                c1++;
            }
            
        }
        return res;
        
    }
};