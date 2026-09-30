class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = prices[0];
        int n = prices.size();

        for(int i=1;i<n;i++){
            if(mini > prices[i]){
                mini = prices[i];
            }else{
                profit = max(profit, prices[i] - mini);
            }
        }
        return profit;
    }
};
