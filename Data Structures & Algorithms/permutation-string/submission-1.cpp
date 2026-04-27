class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp1(26,0);
        vector<int> mp2(26,0);

        int n = s1.size();

        if(s1.size() > s2.size()){
            return false;
        }

        for(int i=0;i<n;i++){
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
