class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(),i=0,j=0,res=-1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minHeap;
        for(int i=0;i<n;i++) minHeap.push({matrix[i][0],{i,0}});
        while(k){
            int i = minHeap.top().second.first, j = minHeap.top().second.second;
            res = minHeap.top().first;
            minHeap.pop();
            if(j+1<n) minHeap.push({matrix[i][j+1],{i,j+1}});
            k--;
        }
        
         return res;                                
    }
};