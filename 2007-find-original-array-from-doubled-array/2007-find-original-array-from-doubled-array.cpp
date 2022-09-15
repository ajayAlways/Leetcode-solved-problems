class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size(),cnt=0;
        if(n%2!=0) return {};
        sort(changed.begin(),changed.end());
        vector<int>res;
        unordered_map<int,int>m;
        for(int i=n-1;i>=0;i--){
            if(m.find(changed[i]*2)!=m.end()){
                res.push_back(changed[i]);
                m[2*changed[i]]--;
                if(m[2*changed[i]]==0) m.erase(2*changed[i]);
            }
            else m[changed[i]]++;
            if(res.size()==n/2) break;
        }
        if(res.size()!=n/2) return {};
        return res;
    }
};