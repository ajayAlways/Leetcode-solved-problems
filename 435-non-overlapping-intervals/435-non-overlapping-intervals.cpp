bool comp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int count=0;
        vector<int>prev = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(prev[1]>intervals[i][0]){
                count++;
            }
            else{
                prev=intervals[i];
            }
        }
        return count;
    }
};