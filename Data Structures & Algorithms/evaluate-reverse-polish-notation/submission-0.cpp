class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto i: tokens){
            if(i == "+" || i == "-" || i == "*" || i == "/"){
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                st.pop();

                if(i == "+"){
                    st.push(v1+v2);
                }else if(i == "-"){
                    st.push(v2-v1);
                }else if(i == "*"){
                    st.push(v1*v2);
                }else if(i == "/"){
                    st.push(v2/v1);
                }
            }else{
                st.push(atoi(i.c_str()));
            }
        }
        return st.top();
    }
};
