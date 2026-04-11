class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();

        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                int w = j-i;
                int h = min(heights[i],heights[j]);

                maxArea = max(maxArea,w*h);
            }
        }
        return maxArea;
    }
};
