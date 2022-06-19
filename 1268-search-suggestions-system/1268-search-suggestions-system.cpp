class Solution {
public:
    int binarySearch(vector<string>& words,string& prefix){
        int l = 0,h = words.size()-1, mid,len = prefix.length(),res=-1;
        while(l<=h){
            mid = l+(h-l)/2;
            string cmp = words[mid].substr(0,len);
            if(cmp==prefix){
                res = mid;
                h = mid-1;
            }
            else if(cmp<prefix) l = mid + 1;
            else h = mid - 1;
        }
        return res;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = searchWord.length(), m =products.size();
        vector<vector<string>>res(n);
        sort(products.begin(),products.end());
        string pref="";
        for(int i=0;i<searchWord.length();i++){
            pref+=searchWord[i];
            int pos = binarySearch(products, pref),count=0;
            if(pos!=-1){
                for(int j=pos;j<m;j++){
                    string cmp = products[j].substr(0,i+1);
                    if(pref==cmp && count<3) res[i].push_back(products[j]);
                    else break;
                    count++;
                }
            }  
        }
        return res;
    }
};