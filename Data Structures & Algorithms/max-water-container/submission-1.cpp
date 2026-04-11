class Solution {
public:
    int maxArea(vector<int>& heights) {
        int lp = 0;
        int rp = heights.size() - 1;
        int maxArea = 0;

        while(lp<=rp){
            int w = rp - lp;
            int ht = min(heights[rp],heights[lp]);
            maxArea = max(maxArea,w*ht);
            heights[lp] < heights[rp] ? lp+=1: rp-=1;
        }
        return maxArea;
    }
};
