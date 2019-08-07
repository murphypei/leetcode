// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example:
// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].


// DFS方法

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        return dfs(digits);
    }

    vector<string> dfs(string digits) {
        if(digits.size() <= 1) {
            vector<string> result;
            if(digits.empty()) {
                return result;
            }
            for(auto s : mp[digits[0]]) {
                result.push_back(s);
            }
            return result;
        }

        vector<string> tmp = dfs(digits.substr(0, digits.size() - 1));
        vector<string> result;
        for(auto tmp_s : tmp) {
            for(auto s : mp[digits[digits.size() - 1]]) {
                result.push_back(tmp_s + s);
            }
        }
        return result;
    }

private:
    unordered_map<char, vector<string>> mp = {
        {'2', vector<string>({"a", "b", "c"})},
        {'3', vector<string>({"d", "e", "f"})},
        {'4', vector<string>({"g", "h", "i"})},
        {'5', vector<string>({"j", "k", "l"})},
        {'6', vector<string>({"m", "n", "o"})},
        {'7', vector<string>({"p", "q", "r", "s"})},
        {'8', vector<string>({"t", "u", "v"})},
        {'9', vector<string>({"w", "x", "y", "z"})}
    };
};