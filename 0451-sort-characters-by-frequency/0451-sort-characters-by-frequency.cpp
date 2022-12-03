class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>,vector<pair<int,char>>>pq;
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        for(auto i:m){
            pq.push({i.second,i.first});
        }
        string ans="";
        while(pq.size()){
            ans+=string(pq.top().first,pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};