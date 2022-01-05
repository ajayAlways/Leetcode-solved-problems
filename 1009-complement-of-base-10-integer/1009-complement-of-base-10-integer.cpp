class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int power=1,ans=0;
        while(n!=0){
            ans+=(1 - (n%2))*power;
            n/=2;
            power*=2;
        }
        return ans;
    }
};