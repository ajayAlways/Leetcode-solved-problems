class Solution {
public:
    int gcd(int x, int y){
        int lim = min(x,y),res=1;
        for(int i=1;i<=lim;i++){
            if(x%i==0 && y%i==0) res = max(res,i);
        }
        return res;
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int x=jug1Capacity, y = jug2Capacity, z = targetCapacity;
        if(x+y<z) return false;
        if(x==z || y==z || x+y==z) return true;
        
        return z%gcd(x,y)==0;
    }
};