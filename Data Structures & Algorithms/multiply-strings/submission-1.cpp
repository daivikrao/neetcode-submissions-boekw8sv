class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        
        int m = num1.size();
        int n = num2.size();

        vector<int> result(m+n);

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int mul = (num1[i]-'0')*(num2[j]-'0');

                int posLow = i + j + 1;
                int posHigh = i + j;

                int sum = mul + result[posLow];

                result[posLow] = sum%10;
                result[posHigh] += sum/10;
            }
        }

        string ans = "";
        int i=0;

        while(i<result.size() && result[i] == 0){
            i += 1;
        }

        for(int j=i;j<result.size();j++){
            ans.push_back(result[j] + '0');
        }

        return ans;
    }
};
