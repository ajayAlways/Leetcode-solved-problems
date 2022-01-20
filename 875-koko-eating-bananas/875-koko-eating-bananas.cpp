class Solution {
public:
    
    bool isValid(vector<int>piles, int h, int k){
        long hours=0;
        for(int i= 0;i<piles.size();i++){
            hours+=(piles[i]+k-1)/k;
            if(hours>h) return false;
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,e=*max_element(piles.begin(),piles.end()),mid,res;
        while(l<=e){
            mid= l+(e-l)/2;
            if(isValid(piles,h,mid)){
                res = mid;
                e=mid-1;
            }
            else l=mid+1;
        }
        return res;
    }
};