class Solution {
public:
    int maxArea(vector<int>& heights) {

        int n = heights.size();
        int lp = 0;
        int rp = n - 1;
        int maxArea = 0;

        while(lp <= rp){
            int w = (rp - lp);
            int h = min(heights[rp],heights[lp]);
            maxArea = max(maxArea, w*h);
            if(heights[lp] < heights[rp]){
                lp += 1;
            }else{
                rp -= 1;
            }
        }
        return maxArea;
    }
};
