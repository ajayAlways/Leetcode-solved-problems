class Trie{
    private:
        Trie *links[2]={};
    public:
        Trie(){}
        
        bool isContainsKey(int bit){
            return this->links[bit]!=NULL;
        }
        
        Trie* get(int bit){
            return this->links[bit];
        }
    
        void put(int bit, Trie *trie){
            this->links[bit] = trie;
        }
    
        void insert(int num){
            Trie *root = this;
            bitset<32>bits(num);
            for(int i=31;i>=0;i--){
                if(!(root->isContainsKey(bits[i]))){
                    root->put(bits[i],new Trie());
                }
                root = root->get(bits[i]);
            }
        }
    
        int XOR(int num){
            Trie *root = this;
            bitset<32>bits(num);
            int maxNum = 0;
            for(int i=31;i>=0;i--){
                if(root->isContainsKey(1-bits[i])){
                    maxNum = maxNum | (1<<i);
                    root = root->get(1-bits[i]);
                }
                else root = root->get(bits[i]);
            }
            
            return maxNum;
        }
};


class Solution {
public:
    bool static comp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size(),inserted=0;
        vector<int>res(n,-1);
        Trie *trie = new Trie();
        for(int i=0;i<n;i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),comp);
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            while(inserted<nums.size() && nums[inserted]<=queries[i][1]){
                trie->insert(nums[inserted++]);
            }
            if(inserted>0) res[queries[i][2]] = trie->XOR(queries[i][0]);
        }
        
        return res;
    }
};