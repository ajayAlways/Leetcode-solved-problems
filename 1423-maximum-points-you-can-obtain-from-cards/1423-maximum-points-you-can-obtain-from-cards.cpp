class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res=0,sum=0, n = cardPoints.size(),temp=k-1;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        res = sum;
        for(int i=n-1;i>=0 && temp>=0;i--){
            sum-=cardPoints[temp--];
            sum+=cardPoints[i];
            res = max(res,sum);
        }
        return res;
    }
};