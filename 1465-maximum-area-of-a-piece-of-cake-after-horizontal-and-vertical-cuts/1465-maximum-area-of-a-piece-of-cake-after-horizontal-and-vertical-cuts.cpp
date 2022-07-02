class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int hc = horizontalCuts.size(), vc = verticalCuts.size(),hMax = 0, vMax = 0, prev=0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        for(auto& i:horizontalCuts){
            vMax = max(vMax,i-prev);
            prev = i;
        }
        vMax = max(vMax,h-prev);
        prev = 0;
        for(auto& i:verticalCuts){
            hMax = max(hMax,i-prev);
            prev = i;
        }
        hMax = max(hMax,w-prev);
        
        return (1LL*vMax*hMax)%1000000007;
    }
};