class Solution {
public:
    int findTheWinner(int n, int k) {
        // O(n^3)         
        vector<int>v(n);
        int pos=0;
        for(int i=1;i<=n;i++) v[i-1]=i;
        while(v.size()>1){
            pos=(pos+k-1)%v.size();
            v.erase(v.begin()+pos);
            pos = (pos)%v.size();
        }
        return v[0];
        // queue<int>q;
        // for(int i=0;i<n;i++) q.push(i+1);
        // while(q.size()>1){
        //     int x = k-1;
        //     while(x--){
        //         int val = q.front();
        //         q.pop();
        //         q.push(val);
        //     }
        //     q.pop();
        // }
        // return q.front();
    }
};