class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices % 2!=0) return {};
        if(cheeseSlices> tomatoSlices/2 || cheeseSlices < tomatoSlices/4) return {};
        
        return {(tomatoSlices-2*cheeseSlices)/2,(4*cheeseSlices - tomatoSlices)/2};
        
    }
};