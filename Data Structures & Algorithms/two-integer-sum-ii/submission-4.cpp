class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;

        int st = 0;
        int e = numbers.size() - 1;

        while(st<=e){
            if((numbers[st] + numbers[e])  == target){
                ans.push_back(st+1);
                ans.push_back(e+1);
                return ans;
            }else if((numbers[st] + numbers[e]) > target){
                e -= 1;
            }else{
                st += 1;
            }
        }
        return ans;
    }
};
