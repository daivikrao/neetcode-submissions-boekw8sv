class Solution {
public:

    string encode(vector<string>& strs) {

        string temp = "";
        for(auto i:strs){
            int length = i.size();
            temp += to_string(length) + "#" + i;
        }
        return temp;
    }

    vector<string> decode(string s) {
        int i = 0;
        int n = s.size();
        vector<string> ans;

        while(i < n){
            int j = i;
            while(s[j] != '#'){
                j += 1;
            }

            int length = stoi(s.substr(i,j-i));
            string v = s.substr(j+1,length);
            ans.push_back(v);

            i = j + 1 + length;
        }
        return ans;
    }
};
