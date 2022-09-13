#include<bitset>

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size(), i = 0;
        while(i<n){
            bitset<8>bits(data[i]);
            int j=7,cnt=0;
            while(j>=0 && bits[j]==1){
                j--;
                cnt++;
            }
            if(!cnt){
                i++;
                continue;
            }
            if(cnt==1 || cnt>4) return false;
            while(cnt>1){
                i++;
                if(i>=n) return false;
                int t = (data[i]>>7 & 1)*10 + (data[i]>>6 & 1);
                if(t!=10) return false;
                cnt--;
            }
            i++;
        }
        
        return true;
    }
};