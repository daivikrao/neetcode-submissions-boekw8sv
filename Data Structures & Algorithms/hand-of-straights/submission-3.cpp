class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
         for(auto i: hand){
            mp[i] += 1;
         }

         if(hand.size() % groupSize != 0){
            return false;
         }

         for(auto [key,val]: mp){
            while(val != 0){
                for(int curr=key;curr<key+groupSize;curr++){
                    if(mp[curr] == 0){
                        return false;
                    }
                    mp[curr] -= 1;
                }
                val -= 1;
            }
         }

        return true;
    }
};
