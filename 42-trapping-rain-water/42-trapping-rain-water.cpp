class Solution {
public:
    int trap(vector<int>& A) {
        int n=A.size();
        int left = 0; int right = n - 1;
        int res = 0;
        int maxleft = 0, maxright = 0;
        while(left <= right){
            if(A[left] <= A[right]){
                maxleft = max(A[left],maxleft);
                res += maxleft-A[left];
                left++;
            }
            else{
                maxright = max(A[right],maxright);
                res += maxright - A[right];
                right--;
            }
        }
        return res;
    }
};