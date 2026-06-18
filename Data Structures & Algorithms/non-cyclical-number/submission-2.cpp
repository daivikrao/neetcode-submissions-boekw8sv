class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> mp;

        while(n!=1 && mp.find(n)==mp.end()){
            long long sum = 0;
            mp.insert(n);

            while(n){
                int digit = n%10;
                sum += digit*digit;
                n = n/10;
            }
            n = sum;
        }
        return n == 1;
    }
};
