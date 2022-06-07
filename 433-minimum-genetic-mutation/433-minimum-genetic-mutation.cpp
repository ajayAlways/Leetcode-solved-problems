class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int res=0,i=0,j=0,iter=0;
        string codes = "ATGC";
        queue<string>q;
        unordered_set<string>m(bank.begin(),bank.end());
        q.push(start);
        if(m.find(end)==m.end()) return -1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                string str = q.front();
                q.pop();
                if(str==end) return res;
                for(int j=0;j<8;j++){
                    char c = str[j];
                    for(int k=0;k<4;k++){
                        str[j] = codes[k];
                        if(m.find(str)!=m.end()){
                            q.push(str);
                            m.erase(str);
                        }
                    }
                    str[j] = c;
                }
            }
            res++;
        }
        return -1;
    }
};