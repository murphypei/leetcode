// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }
        char common_char;
        string result = "";
        int idx = 0;
        while(idx < strs[0].size()) {
            common_char = strs[0][idx];
            for(int i = 1; i < strs.size(); ++i) {
                if(strs[i][idx] != common_char) {
                    return result;
                }
            }
            result += common_char;
            idx++;
        }
        return result;
    }
};