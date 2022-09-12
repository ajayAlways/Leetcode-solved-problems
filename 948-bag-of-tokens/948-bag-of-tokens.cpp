class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size(),i=0,j=n-1,res=0,score=0;
        
        sort(tokens.begin(),tokens.end());
        
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                i++;
                continue;
            }
            res = max(score,res);
            if(score>0 && power<tokens[i]){
                power+=tokens[j];
                score--;
                j--;
            }
            else break;
        }
        res = max(score,res);
        return res;
    }
};