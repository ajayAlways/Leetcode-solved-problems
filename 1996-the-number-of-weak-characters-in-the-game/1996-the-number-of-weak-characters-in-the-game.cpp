class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0] < b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        int n = prop.size();
        sort(prop.begin(),prop.end(),comp);
        int maxi = prop.back()[1],res=0;
        
        for(int i=n-1;i>=0;i--){
            if(prop[i][1]<maxi) res++;
            maxi = max(prop[i][1],maxi);
        }
        
        return res;
    }
};