class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int>bits(32,0);
        for(auto i:candidates){
            int index = 31;
            while(i>0){
                bits[index--]+=(i%2);
                i/=2;
            }
        }
        return *max_element(bits.begin(),bits.end());
    }
};