// Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

// Example 1:
// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"]
// Note:
// You may use one character in the keyboard more than once.
// You may assume the input string will only contain letters of alphabet.


// 将键盘的每一行存储为set，然后遍历输入的string来判断字符是否在set中

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> alphabet;
        alphabet.push_back("qwertyuiop");
        alphabet.push_back("asdfghjkl");
        alphabet.push_back("zxcvbnm");
        
        vector<string> results;
        
        for (auto &w : words) {
            for (auto &a : alphabet) {
                if (isValid(w, a)) {
                    results.push_back(w);
                }
            }
        }
        
        return results;
        
    }
    
    // 判断一个字符串dst是否只由另一个字符串src中的字符组成
    bool isValid(const string &dst, const string &src) {
        unordered_set<char> srcSet(src.cbegin(), src.cend());
        // 忽略大小写
        for (auto &a : dst) {
            if (srcSet.find(a) == srcSet.end() && srcSet.find(tolower(a)) == srcSet.end()) {
                //cout << a << endl;
                return false;
            }
        }
        return true;
    }
};
