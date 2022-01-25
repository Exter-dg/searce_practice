// Leetcode - https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int lastInvalidPos = -1;
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push(i);
            else {
                // s[i] is ')'
                if (st.empty())
                    st.push(i);
                else {
                    if (s[st.top()] == '(') {
                        // match braces
                        st.pop();
                        // find the last invalid (if doesnt exists then -1)
                        if (!st.empty())
                            lastInvalidPos = st.top();
                        else
                            lastInvalidPos = -1;
                        res = max(res, i - lastInvalidPos);
                    } else {
                        st.push(i);
                    }
                }
            }
        }
        return res;
    }
};