class NumArray {
private:
    vector<int>stree;
    int n=0;
public:
    
    void buildSegTree(vector<int>&nums,int start, int end, int idx){
        if(start==end){
            stree[idx] = nums[start];
            return;
        }
        int mid = start + (end-start)/2;
        buildSegTree(nums,start,mid,idx*2+1);
        buildSegTree(nums,mid+1,end,idx*2+2);
        stree[idx] = stree[idx*2+1] + stree[idx*2+2];
    }
    
    void updateSegTree(int start, int end, int pos, int index, int val){
        //  no overlap
        if(start>index || end<index) return;
        
        //total overlap
        if(start==end && start==index){
            stree[pos] = val;
            return;
        }
        
        //partial overlap
        int mid = start + (end-start)/2;
        updateSegTree(start,mid,pos*2+1,index,val);
        updateSegTree(mid+1,end,pos*2+2,index,val);
        
        stree[pos] = stree[pos*2+1]+stree[pos*2+2];
    }
    
    int querySegTree(int start, int end, int idx, int left, int right){
        //total overlap
        if(left<=start && right>=end) return stree[idx];
        
        //no overlap
        if(left>end || right<start) return 0;
        
        //partial overlap
        int mid = start + (end-start)/2;
        return querySegTree(start,mid,idx*2+1,left,right)+querySegTree(mid+1,end,idx*2+2,left,right);
        
    }
    
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        this->stree = vector<int>(4*n,0);
        buildSegTree(nums,0,n-1,0);
    }
    
    void update(int index, int val) {
        updateSegTree(0,n-1,0,index,val);
    }
    
    int sumRange(int left, int right) {
        return querySegTree(0,n-1,0,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */