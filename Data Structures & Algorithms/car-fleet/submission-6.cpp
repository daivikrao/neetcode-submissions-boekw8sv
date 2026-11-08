class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> ans;

        for(int i=0;i<position.size();i++){
            ans.push_back({position[i],speed[i]});
        }

        sort(ans.begin(),ans.end(),greater<pair<int,int>>());
        stack<double> st;

        for(auto car: ans){
            int pos = car.first;
            int sp = car.second;
            double timeTaken = (double)(target - pos)/sp;
            if(st.empty() || timeTaken > st.top()){
                st.push(timeTaken);
            }
        }
        return st.size();
    }
};
