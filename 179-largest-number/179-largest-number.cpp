class Solution {
public:
    static bool comp(int &a, int &b){
        string as = to_string(a), bs = to_string(b);
        return as+bs > bs+as;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),comp);
        string res = "";
        for(auto& i:nums){
            res+=to_string(i);
        }
        while(res.length()>1 && res[0]=='0'){
            res.erase(res.begin()+0);
        }
        return res;
    }
};