class Solution {
public:
    bool static comp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size(),res=0,maxi;
        sort(properties.begin(),properties.end(),comp);
        maxi = properties.back()[1];
        for(int i=n-1;i>=0;i--){
            if(properties[i][1]<maxi) res++;
            maxi = max(properties[i][1],maxi);
        }
        
        return res;
    }
};