class Solution {
public:
    int myAtoi(string s) {
        int num=0,sign=1,leading=1,signTime=0,isNumApr=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(leading) continue;
                else break;
            }
            else if(s[i]=='-' && !isNumApr && signTime++<1){sign=-1;leading=0;}
            else if(s[i]=='+' && !isNumApr && signTime++<1){sign=1; leading=0;}
            else if(s[i] >= '0' && s[i] <= '9'){
                    isNumApr=1;
                    if (num >  INT_MAX / 10 || (num == INT_MAX / 10 && s[i] - '0' > 7)) {
                        if (sign == 1) return INT_MAX;
                        else return INT_MIN;
                    }
                    num  = 10 * num + (s[i] - '0');
                    leading=0;
            }
           else{
               break;
           }     
            
        }
        return sign*num;
    }
};