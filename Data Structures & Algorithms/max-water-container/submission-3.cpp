class Solution {
public:
    int maxArea(vector<int>& heights) {
        int s = 0;
        int e = heights.size()-1;
        int maxArea = 0;

        while(s<=e){
            int h = min(heights[s],heights[e]);
            maxArea = max(maxArea,h*(e - s));
            if(heights[s] > heights[e]){
                e -= 1;
            }else{
                s += 1;
            }
        }
        return maxArea;
    }
};
