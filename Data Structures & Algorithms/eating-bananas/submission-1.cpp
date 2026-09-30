class Solution {
public:
    bool isValid(int mid, int h, vector<int>& piles){
        int hh = 0;
        for(auto i: piles){
            hh += ceil((double)i/mid);
        }

        return hh <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        int ans;

        while(left <= right){
            int mid = left + (right - left)/2;
            if(isValid(mid,h,piles)){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};
