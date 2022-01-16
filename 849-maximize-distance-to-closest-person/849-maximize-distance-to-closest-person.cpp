class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans=0,j=-1,n=seats.size();
        
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                ans = j<0 ? i:max(ans,(i-j)/2);
                j=i;
            }
        }
        ans = max(ans,n-j-1);

        return ans;
    }
};