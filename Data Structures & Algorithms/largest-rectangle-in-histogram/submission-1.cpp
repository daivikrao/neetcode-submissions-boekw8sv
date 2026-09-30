class Solution {
public:
    void findNSE(vector<int>& nse, vector<int> heights){
        stack<int> st;
        int n = heights.size();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                nse[i] = n;
            }else{
                nse[i] = st.top();
            }
            st.push(i);
        }
    }

    void findPSE(vector<int>& pse, vector<int> heights){
        stack<int> st;
        int n = heights.size();

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                pse[i] = -1;
            }else{
                pse[i] = st.top();
            }
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nse(n);
        vector<int> pse(n);

        findNSE(nse,heights);
        findPSE(pse,heights);
        int maxi = 0;

        for(int i=0;i<n;i++){
            maxi = max(maxi,heights[i]*(nse[i] - pse[i] - 1));
        }
        return maxi;
    }
};
