class Solution {
public:
    
//     char find(char &a,vector<char>&parent){
//         if(parent[a-'a']==a) return parent[a-'a'];
        
//         return parent[a-'a'] = find(parent[a-'a'],parent);
//     }
    
//     void uni(char &a, char &b,vector<char>&parent){
//         parent[a-'a'] = find(b,parent);
//         return;
//     }
    
//     bool equationsPossible(vector<string>& equations) {
//         vector<char>parent(26,'a');
//         for(int i=0;i<26;i++) parent[i] = 'a'+i;
        
//         for(auto& i:equations){
//             if(i[1]=='=') uni(i[0],i[3],parent);
//         }
        
//         for(auto& i:equations){
//             if(i[1]=='='){
//                 if((find(i[0],parent)!=i[0] || find(i[3],parent)!=i[3]) && find(i[0],parent)!=find(i[3],parent)) return false;
//             }
//             else{
//                 if(find(i[0],parent)==find(i[3],parent)) return false;
//             }
//         }
        
//         return true;
//     }
    int uf[26];
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i) uf[i] = i;
        for (string e : equations)
            if (e[1] == '=')
                uf[find(e[0] - 'a')] = find(e[3] - 'a');
        for (string e : equations)
            if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a'))
                return false;
        return true;
    }

    int find(int x) {
        if (x != uf[x]) uf[x] = find(uf[x]);
        return uf[x];
    }
};