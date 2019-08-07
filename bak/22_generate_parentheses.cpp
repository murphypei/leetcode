// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        dfs(result, n, n, "");
        return result;
    }
    
    void dfs(vector<string> &result, int left, int right, string s) {
        if(0 == left && 0 == right) {
            // cout << "push: " << s << endl;
            result.emplace_back(s);
        }
        
        if(left > 0) {
            // cout << "left: " << s << endl;
            dfs(result, left-1, right, s+"(");
        }
        if(right > 0 && right > left) {
            // cout << "right: " << s << endl;
            dfs(result, left, right-1, s+")");
        }
    }
    
};