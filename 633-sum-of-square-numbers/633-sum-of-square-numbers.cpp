class Solution {
public:
    bool judgeSquareSum(int c) {
        int j = sqrt(c);
        unordered_set<int>st;
        for(int i=0;i<=j;i++){
            st.insert(i*i);
        }
        for(int i=0;i<=j;i++){
            int num = c - i*i;
            if(st.count(num)==1) return true;
        }
        return false;
    }
};