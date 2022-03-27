class Solution {
public:
    int numberOfOnes(vector<int>v){
        int l=0,h=v.size()-1,mid,pos=-1;
        while(l<=h){
            mid=l+(h-l)/2;
            if(v[mid]==1){
                l=mid+1;
                pos=mid;
            }
            else h=mid-1;
        }
        if(pos==-1) return 0;
        return pos+1;
    }
    static bool cmp(pair<int,int>a, pair<int,int>b){
        if(a.second!=b.second) return a.second<b.second;
        else return a.first < b.first;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>feq;
        for(int i=0;i<mat.size();i++){
            feq.push_back({i,numberOfOnes(mat[i])});
        }
        sort(feq.begin(),feq.end(),cmp);
        vector<int>res;
        for(int i=0;i<k;i++){
            res.push_back(feq[i].first);
        }
        return res;
    }
};