class Solution {
public:
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int res=0;
        queue<pair<int,int>>q;
        vector<vector<int>>vis(6000,vector<int>(2,0));
        unordered_set<int>s(forbidden.begin(),forbidden.end());
        q.push({0,1});
        q.push({0,0});
        vis[0][0] = 1;
        vis[0][0] = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int num = q.front().first, state = q.front().second;
                q.pop();
                if(num==x) return res;
                if(state){
                    if(num+a<6000 && vis[num+a][0]==0 && !s.count(num+a)){
                        q.push({num+a,1});
                        vis[num+a][0] = 1;
                    }
                    if(num-b>=0 && vis[num-b][1]==0 && !s.count(num-b)){
                        q.push({num-b,0});
                        vis[num-b][1] = 1;
                    }
                }
                else{
                    if(num+a<6000 && vis[num+a][0]==0 && !s.count(num+a)){
                        q.push({num+a,1});
                        vis[num+a][0] = 1;
                    }
                }
            }
            res++;
        }
        return -1;
    }
};