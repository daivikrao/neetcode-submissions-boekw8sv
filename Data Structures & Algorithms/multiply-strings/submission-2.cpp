class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }

        int m = num1.size();
        int n = num2.size();
        vector<int> ans(m+n);

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int res = (num1[i] - '0')*(num2[j] - '0');

                int posHigh = i + j + 1;
                int posLow = i + j;

                int sum = res + ans[posHigh];

                ans[posHigh] = sum%10;
                ans[posLow] += sum/10;
            }
        }


        string st = "";
        int i=0;

        while(i<ans.size() && ans[i] == 0){
            i += 1;
        }

        for(int j=i;j<ans.size();j++){
            st.push_back(ans[j] + '0');
        }
        return st;
    }
};
