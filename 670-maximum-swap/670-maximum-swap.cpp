class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int maxindx = str.length()-1,leftindx=-1,rightindx=-1;
        for(int i=str.length()-1;i>=0;i--){
            if(str[i]>str[maxindx]){
                maxindx = i;
                continue;
            }
            if(str[i]<str[maxindx]){
                leftindx = i;
                rightindx = maxindx;
            }
               
        }
        if(leftindx==-1) return num;
        swap(str[leftindx],str[rightindx]);
        return stoi(str);
    }
};