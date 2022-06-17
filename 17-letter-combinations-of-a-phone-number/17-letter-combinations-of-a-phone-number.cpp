class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string arr[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n = digits.length();
        vector<string>res;
        if(n==0) return {};
        // if(n==1){
        //     string s = arr[digits[0]-'0'],temp;
        //     for(int i=0;i<s.length();i++){
        //         temp.push_back(s[i]);
        //         res.push_back(temp);
        //         temp.pop_back();
        //     }
        // }
        // else if(n==2){
        //     string s = arr[digits[0]-'0'],temp;
        //     for(int i=0;i<s.length();i++){
        //         temp.push_back(s[i]);
        //         string s2 = arr[digits[1]-'0'];
        //         for(int j=0;j<s2.length();j++){
        //             temp.push_back(s2[j]);
        //             res.push_back(temp);
        //             temp.pop_back();
        //         }
        //         temp.pop_back();
        //     }
        // }
        // else if(n==3){
        //     string s = arr[digits[0]-'0'],temp;
        //     for(int i=0;i<s.length();i++){
        //         temp.push_back(s[i]);
        //         string s2 = arr[digits[1]-'0'];
        //         for(int j=0;j<s2.length();j++){
        //             temp.push_back(s2[j]);
        //             string s3 = arr[digits[2]-'0'];
        //             for(int k=0;k<s3.length();k++){
        //                 temp.push_back(s3[k]);
        //                 res.push_back(temp);
        //                 temp.pop_back();
        //             }
        //             temp.pop_back();
        //         }
        //         temp.pop_back();
        //     }
        // }
        // else if(n==4){
        //     string s = arr[digits[0]-'0'],temp;
        //     for(int i=0;i<s.length();i++){
        //         temp.push_back(s[i]);
        //         string s2 = arr[digits[1]-'0'];
        //         for(int j=0;j<s2.length();j++){
        //             temp.push_back(s2[j]);
        //             string s3 = arr[digits[2]-'0'];
        //             for(int k=0;k<s3.length();k++){
        //                 temp.push_back(s3[k]);
        //                 string s4 = arr[digits[3]-'0'];
        //                 for(int l=0;l<s4.length();l++){
        //                     temp.push_back(s4[l]);
        //                     res.push_back(temp);
        //                     temp.pop_back();
        //                 }
        //                 temp.pop_back();
        //             }
        //             temp.pop_back();
        //         }
        //         temp.pop_back();
        //     }
        // }
        res.push_back("");
        for(auto& digit:digits){
            vector<string>temp;
            for(auto& i:arr[digit-'0']){
                for(auto& j:res){
                    temp.push_back(j+i);
                }
            }
            res.swap(temp);
        }
        return res;
    }
};