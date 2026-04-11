class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;

        for(auto i:gas){
            totalGas += i;
        }

        for(auto i:cost){
            totalCost += i;
        }

        if(totalGas < totalCost){
            return -1;
        }

        int start = 0;
        int current_sum = 0;

        for(int i=0;i<gas.size();i++){
            current_sum += (gas[i] - cost[i]);

            if(current_sum < 0){
                start = i + 1;
                current_sum = 0;
            }
        }
        return start;
    }
};
