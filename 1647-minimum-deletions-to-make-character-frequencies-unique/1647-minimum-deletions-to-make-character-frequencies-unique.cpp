class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26,0);
        int res=0,flag;
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        do{
            flag = 0;
            sort(freq.begin(),freq.end());
            for(int i=24;i>=0;i--){
            if(freq[i]!=0){
                int j=i+1;
                // while(j<26 && freq[j]==0) j++;
                if(j<26 && freq[j]==freq[i]){
                        res++;
                        freq[i]--;
                        flag = 1;
                        break;
                    }
                }
            }    
        }while(flag);
        
        return res;
    }
};