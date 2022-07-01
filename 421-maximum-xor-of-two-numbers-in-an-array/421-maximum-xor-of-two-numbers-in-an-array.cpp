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
    int findMaximumXOR(vector<int>& nums) {
        Trie *root = new Trie();
        int res = 0;
        for(auto& i:nums){
            root->insert(i);
        }
        for(auto& i:nums){
            int temp = root->XOR(i);
            res = max(res, temp);
        }
        
        return res;
    }
};