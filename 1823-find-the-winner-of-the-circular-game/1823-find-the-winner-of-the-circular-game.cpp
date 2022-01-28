class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>v(n);
        int pos=0;
        for(int i=1;i<=n;i++) v[i-1]=i;
        while(v.size()>1){
            pos=(pos+k-1)%v.size();
            v.erase(v.begin()+pos);
            pos = (pos)%v.size();
        }
        return v[0];
    }
};