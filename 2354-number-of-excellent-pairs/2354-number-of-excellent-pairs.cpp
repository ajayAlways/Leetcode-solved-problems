#include<bitset>

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_map<int,int>bits;
        unordered_set<int>st(nums.begin(),nums.end());
        long long res=0;
        for(auto& i:st){
            bitset<32>temp(i);
            bits[temp.count()]++;
        }
        for(int i=1;i<=30;i++){
            for(int j=1;j<=30;j++){
                if(i+j>=k) res+=bits[i]*bits[j];
            }
        }
        return res;
    }
};