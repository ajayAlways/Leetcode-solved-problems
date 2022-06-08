class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>degree(n,0);
        unordered_set<string>s;
        int res=0;
        for(auto& i:roads){
            degree[i[0]]++;
            degree[i[1]]++;
        }
        for(auto& i:roads){
            string str,rev;
            str.append(to_string(i[0])),str.push_back('-'),str.append(to_string(i[1]));
            rev.append(to_string(i[1])),rev.push_back('-'),rev.append(to_string(i[0]));
            s.insert(str);
            s.insert(rev);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string str,rev;
                str.append(to_string(i)),str.push_back('-'),str.append(to_string(j));
                rev.append(to_string(j)),rev.push_back('-'),rev.append(to_string(i));
                
                if(!s.count(str) || !s.count(rev)) res = max(res,degree[i]+degree[j]);
                else res = max(res,degree[i]+degree[j]-1);
            }
        }
        return res;
    }
};