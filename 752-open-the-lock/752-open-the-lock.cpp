class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int res=0;
        queue<string>q;
        unordered_set<string>m(deadends.begin(),deadends.end());
        q.push("0000");
        if(m.find("0000")!=m.end()) return -1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                string str = q.front();
                q.pop();
                if(str==target) return res;
                for(int j=0;j<4;j++){
                    int d = str[j]-'0';
                    for(int k=-1;k<2;k++){
                        char c = (d + (k + 10)%10)%10 + '0';
                        str[j] = c;
                        if(m.find(str)==m.end()){
                            q.push(str);
                            m.insert(str);
                        }
                    }
                    str[j] = (d+'0');
                }
            }
            res++;
        }
        return -1;
    }
};