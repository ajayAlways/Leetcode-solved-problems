class Solution {
public:
    int countSubMats(vector<int>nums, int target){
        int n = nums.size(),prefixSum=0,res=0;
        unordered_map<int,int>m;
        m[0] = 1;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            if(m.find(prefixSum-target)!=m.end()) res+=m[prefixSum-target];
            m[prefixSum]++;
        }
        return res;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(),res=0;
        // O(n^4) solution - TLE
        // vector<vector<int>>sum(m+1,vector<int>(n+1,0));
        // for(int i=1;i<m+1;i++){
        //     for(int j=1;j<n+1;j++){
        //         sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];
        //     }
        // }
        // for(int x1=0;x1<m;x1++){
        //     for(int y1=0;y1<n;y1++){
        //         for(int x2=x1+1;x2<m+1;x2++){
        //             for(int y2=y1+1;y2<n+1;y2++){
        //                 int calcSum = sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
        //                 if(calcSum==target) res=res+1;
        //             }
        //         }
        //     }
        // }
        
        for(int i=0;i<m;i++){
            vector<int>nums(n,0);
            for(int j=i;j<m;j++){
                for(int k=0;k<n;k++) nums[k]+=matrix[j][k];
                res+=countSubMats(nums,target);
            }
        }
        return res;
    }
};