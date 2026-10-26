class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int count = 0;

        for(int i=0;i<=n;i++){
            int temp = i;
            while(temp){
                if(temp&1 == 1){
                    count += 1;
                }
                temp >>= 1;
            }
            ans.push_back(count);
            count = 0;
        }
        return ans;
    }
};
