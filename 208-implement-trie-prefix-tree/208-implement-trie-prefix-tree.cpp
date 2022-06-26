class Trie {
private:
    Trie* alpha[26] = {};
    bool flag = false;
    
public:
    Trie() {}
    
    void insert(string word) {
        Trie* root = this;
        for(int i=0;i<word.length();i++){
            if(root->alpha[word[i]-'a']==NULL){
                Trie *trie = new Trie();
                root->alpha[word[i]-'a'] = trie;
            }
            root = root->alpha[word[i]-'a'];
        }
        root->flag = true;
    }
    
    bool search(string word) {
        Trie* root = this;
        for(int i=0;i<word.length();i++){
            if(root->alpha[word[i]-'a']==NULL) return false;
            root = root->alpha[word[i]-'a'];
        }
        return root->flag;
    }
    
    bool startsWith(string prefix) {
        Trie* root = this;
        for(int i=0;i<prefix.length();i++){
            if(root->alpha[prefix[i]-'a']==NULL) return false;
            root = root->alpha[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */