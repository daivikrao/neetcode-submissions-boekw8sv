class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;

        while(n){
            if(n&1 == 1){
                result += 1;
            }
            n >>= 1;
        }
        return result;
    }
};
