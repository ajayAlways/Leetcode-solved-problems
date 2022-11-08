class Solution {
public:
    string makeGood(string s) {
        while(true){
            string temp = "";
            int flag = 0;
            for(int i=0;i<s.length();i++){
                if(i==0) temp+=s[i];
                else{
                    if((temp.back()>='a' && temp.back()<='z' && s[i]>='A' && s[i]<='Z') || (temp.back()>='A' && temp.back()<='Z' && s[i]>='a' && s[i]<='z')){
                        if(tolower(temp.back())==tolower(s[i])){
                            temp.pop_back();
                            flag=1;
                        }
                        else temp+=s[i];
                    }
                    else temp+=s[i];
                }
            }
            
            if(!flag) return s;
            s = temp;
        }
        
        return s;
    }
};