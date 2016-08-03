// Given two strings s and t, write a function to determine if t is an anagram of s.

// For example,
// s = "anagram", t = "nagaram", return true.
// s = "rat", t = "car", return false.

// Note:
// You may assume the string contains only lowercase alphabets.

// Follow up:
// What if the inputs contain unicode characters? How would you adapt your solution to such case?

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        unordered_map<char, int> charset;

        // 将一个单词字符信息统计在map中
        for(string::size_type i = 0; i != s.size(); ++i) {
            char c = s[i];
            charset[c]++;
        }
        
        // 查看单词信息
        for(unordered_map<char, int>::iterator iter = charset.begin(); iter != charset.end(); ++iter) {
            cout << iter->first << " : " << iter->second << endl;
        }
        

        // 利用上述的map来检查另一个单词的字符统计信息
        for(string::size_type i = 0; i != t.size(); ++i) {
            char c = t[i];
            charset[c]--;
            if(charset[c] == 0) {
                charset.erase(c);
            }
        }
        
        if(charset.empty())
            return true;
        else
            return false;
    }
};