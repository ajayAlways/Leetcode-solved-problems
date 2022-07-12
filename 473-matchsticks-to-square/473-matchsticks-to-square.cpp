class Solution {
public:
    
    bool isPossible(vector<int>& sticks,vector<int>& sides, int pos,int side){
        if(pos>=sticks.size()){
            return sides[0]==side && sides[1]==side && sides[2]==side && sides[3]==side;
        }
        for(int i=0;i<4;i++){
            if(sides[i]+sticks[pos]<=side){
                sides[i]+=sticks[pos];
                if(isPossible(sticks,sides, pos+1,side)) return true;
                sides[i]-=sticks[pos];
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if(n<4) return false;
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        long long sum = accumulate(matchsticks.begin(),matchsticks.end(),0),prefixSum=0;
        if(sum%4!=0) return false;
        int side = sum/4,count=0;
        vector<int>sides(4,0);
        return isPossible(matchsticks,sides,0,side);
    }
};