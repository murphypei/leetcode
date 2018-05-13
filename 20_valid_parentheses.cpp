// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.


class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) {
            return true;
        }

        unordered_set<char> lefts{'(', '{', '['};
        unordered_map<char, char> parentheses{
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        stack<char> st;
        for(auto c : s) {
            if(lefts.find(c) != lefts.end()) {
                st.push(c);
            }
            else if(st.empty() || parentheses[c] != st.top()) {
                return false;
            }
            else {
                st.pop();
            }
        }
        return st.empty() ? true : false;
    }
};