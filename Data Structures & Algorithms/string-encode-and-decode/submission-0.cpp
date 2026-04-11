class Solution {
public:

    string encode(vector<string>& strs) {
        string temp = "";

        for(auto i: strs){
            int length = i.size();
            temp += to_string(length) + "#" + i;
        }

        return temp;
    }

    vector<string> decode(string s) {
        vector<string> v;

        int i = 0;

        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j += 1;
            }

            int length = stoi(s.substr(i,j-i));
            v.push_back(s.substr(j+1,length));
            i = j + 1 + length;
        }
        return v;
    }
};
