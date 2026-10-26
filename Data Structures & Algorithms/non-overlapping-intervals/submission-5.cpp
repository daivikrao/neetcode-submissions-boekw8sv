class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Similar to N meetings in a room

        sort(intervals.begin(),intervals.end(),cmp);

        int cnt = 1;
        int freeTime = intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] >= freeTime){
                cnt += 1;
                freeTime = intervals[i][1];
            }
        }
        return intervals.size() - cnt;
    }
};
