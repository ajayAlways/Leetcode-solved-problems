class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int A=0,B=n-1,C=n-1,D=0,i=1;
        vector<vector<int>>ans(n,vector<int>(n,0));
        while(A<=C || D<=B){
            for(int j=D;j<=B;j++){
                ans[A][j] = i;
                i++;
            }
            A++;
            for(int j=A;j<=C;j++){
                ans[j][B]= i;
                i++;
            }
            B--;
            for(int j=B;j>=D;j--){
                ans[C][j]=i;
                i++;
            }
            C--;
            for(int j=C;j>=A;j--){
                ans[j][D]=i;
                i++;
            }
            D++;
        }
        return ans;
    }
};