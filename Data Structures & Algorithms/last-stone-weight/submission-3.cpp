class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1){
            return stones[0];
        }

        while(stones.size()>1){
            sort(stones.begin(),stones.end());
            int largest = stones.back();
            stones.pop_back();

            int second_largest = stones.back();
            stones.pop_back();

            if(largest == second_largest){
                continue;
            }else{
                stones.push_back(largest - second_largest);
            }
        }
        if(stones.size() == 0){
            return 0;
        }
        return stones[0];
    }
};
