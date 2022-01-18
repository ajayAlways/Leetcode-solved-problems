class Solution {
public:
    int numberOfSubstrings(string s) {
        //  Sliding Window Solution        
        // vector<int>v(3,0);
        // int j=0,count=0;
        // for(int i=0;i<s.length();i++){
        //     v[s[i]-'a']++;
        //     while(v[0]>0 && v[1]>0 && v[2]>0){
        //         v[s[j]-'a']--;
        //         j++;
        //     }
        //     count+=j;
        // }
        
        // without sliding window
        int a=-1,b=-1,c=-1,count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a') a=i;
            else if(s[i]=='b') b=i;
            else c=i;
            count+=min(a,min(b,c))+1;
        }
        return count;
    }
};