class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(),res=0;
        if(n==1) return 1;
        sort(points.begin(),points.end());
        unordered_map<float,int>m2;
        for(int i=0;i<n-1;i++){
            m2 = unordered_map<float,int>();
            for(int j=i+1;j<n;j++){
                if(points[i][0]!=points[j][0]){
                    float slope = (float)(points[j][1]-points[i][1])/(points[j][0]-points[i][0]);
                    m2[slope]++;
                }
                else if(points[j][1]-points[i][1]>0) m2[INT_MAX]++;
                else m2[INT_MIN]++;
            }
            for(auto& sl:m2) res = max(res,sl.second);
        }
        
        return res+1;
    }
};