class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }

        int n = s1.size();
        vector<int> mp1(26);
        vector<int> mp2(26);

        for(int i=0;i<s1.size();i++){
            mp1[s1[i] - 'a'] += 1;
            mp2[s2[i] - 'a'] += 1;
        }

        if(mp1 == mp2){
            return true;
        }

        for(int i=n;i<s2.size();i++){
            mp2[s2[i] - 'a'] += 1;
            mp2[s2[i-n] - 'a'] -= 1;

            if(mp1 == mp2){
                return true;
            }
        }
        return false;
    }
};
