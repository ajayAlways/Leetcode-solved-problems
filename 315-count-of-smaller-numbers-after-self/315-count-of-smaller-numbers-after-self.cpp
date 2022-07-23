class Solution {
public:
    
    void countSmall(vector<pair<int,int>>::iterator l, vector<pair<int,int>>::iterator r,vector<int>&res){
        if(r-l<=1) return;
        auto mid = l + (r-l)/2;
        countSmall(l,mid,res);
        countSmall(mid,r,res);
        for(auto i=l,j=mid;i<mid;i++){
            while(j<r && j->first < i->first) j++;
            res[i->second]+= j - mid;
        }
        inplace_merge(l,mid,r);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,0);
        vector<pair<int,int>>pairs;
        for(int i=0;i<n;i++) pairs.push_back({nums[i],i});
        
        countSmall(pairs.begin(),pairs.end(),res);
        
        return res;
    }
};