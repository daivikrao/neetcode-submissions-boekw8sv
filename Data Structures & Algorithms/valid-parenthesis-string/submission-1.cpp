class Solution {
public:
    bool checkValidString(string s) {
        int min = 0;
        int max = 0;

        for(auto i: s){
            if(i == '('){
                min += 1;
                max += 1;
            }else if(i == ')'){
                min -= 1;
                max -= 1;
            }else{
                min -= 1;
                max += 1;
            }

            if(min < 0){
                min = 0;
            }
            if(max < 0){
                return false;
            }
        }
        return min == 0;
    }
};
