class Solution {
public:
    vector<int> grayCode(int n) {
        bitset<32>bits(0);
        unordered_set<int>st;
        st.insert(0);
        vector<int>res;
        res.push_back(0);
        while(true){
            int flag = 0;
            for(int i=n-1;i>=0;i--){
                bits[i] = 1-bits[i];
                int next = (int)bits.to_ulong();
                if(!st.count(next)){
                    st.insert(next);
                    res.push_back(next);
                    flag=1;
                    break;
                }
                else{
                    bits[i] = 1-bits[i];
                }
            }
            if(!flag) break;
        }

        return res;
    }
};