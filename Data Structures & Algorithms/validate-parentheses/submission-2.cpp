class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto i: s){
            if(i == '[' || i == '(' || i == '{'){
                st.push(i);
            }else{
                if(!st.empty()){
                    char ans = st.top();
                    st.pop();
                    if(i == ']' && ans != '['){
                        return false;
                    }else if(i == '}' && ans != '{'){
                        return false;
                    }else if(i == ')' && ans != '('){
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }

        if(st.empty()){
            return true;
        }
        return false;
    }
};
