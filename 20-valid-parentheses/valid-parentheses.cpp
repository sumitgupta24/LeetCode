class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

        stack<char> st;

        for(auto& str: s) {
            if(str == '(' || str == '{' || str == '[') st.push(str);
            else if(!st.empty() && st.top() == '(' && str == ')') st.pop();
            else if(!st.empty() && st.top() == '[' && str == ']') st.pop();
            else if(!st.empty() && st.top() == '{' && str == '}') st.pop();
            else return false;
        }

        return st.empty();
    }
};