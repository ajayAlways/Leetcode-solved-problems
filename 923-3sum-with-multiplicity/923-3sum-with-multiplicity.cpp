class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,long>m;
        int MOD = 1e9 + 7;
        long long res=0;
        for(auto& i:arr) m[i]++;
        
        for(auto& it1:m){
            for(auto& it2:m){
                int i=it1.first, j = it2.first, k = target - i - j;
                if(!m.count(k)) continue;
                if(i==j && j==k){
                    res+= m[i] * (m[i]-1) * (m[i]-2)/6;
                    res%=MOD;
                }
                else if(i==j && j!=k){
                    res+=(m[i]*(m[i]-1)/2)*m[k];
                    res%=MOD;
                }
                else if(i<j && j<k){
                    res+= m[i]*m[j]*m[k];
                    res%=MOD;
                }
            }
        }
        
        return res;
    }
};