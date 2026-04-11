/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> s1;
        vector<int> s2;

        for(int i=0;i<intervals.size();i++){
            s1.push_back(intervals[i].start);
            s2.push_back(intervals[i].end);
        }

        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());

        int i=0;
        int j=0;
        int cnt=0;
        int maxcnt=0;

        while(i<s1.size()){
            if(s1[i] < s2[j]){
                cnt += 1;
                i += 1;
            }else{
                cnt -= 1;
                j += 1;
            }
            maxcnt = max(maxcnt,cnt);
        }
        return maxcnt;
    }
};
