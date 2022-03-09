class Solution {
public:
    bool judgeSquareSum(int c) {
        int j = sqrt(c);
        unordered_set<int>st;
        
        for(int i=0;i<=j;i++){
            double num1 = sqrt(c - i*i);
            int num2 = sqrt(c - i*i);
            if(num1==num2) return true;
        }
        return false;
    }
};