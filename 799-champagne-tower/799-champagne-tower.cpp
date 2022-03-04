class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>res(102,vector<double>(102,0.0));
        res[0][0] = double(poured);
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<i+1;j++){
                double val = (res[i][j]-1.0)/2.0;
                if(val>0){
                    res[i+1][j]+=val;
                    res[i+1][j+1]+=val;
                }
            }
    
        }
        return min(1.0,res[query_row][query_glass]);
    }
};