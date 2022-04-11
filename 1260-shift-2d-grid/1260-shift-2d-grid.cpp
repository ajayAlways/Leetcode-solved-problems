class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>temp;
        int l=0;
        for(auto& i:grid){
            for(auto& j:i) temp.push_back(j);
        }
        reverse(temp.begin(),temp.end());
        reverse(temp.begin()+(k%temp.size()),temp.end());
        reverse(temp.begin(),temp.begin()+(k%temp.size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]=temp[l++];
            }
        }
        return grid;
    }
};