// Given a pattern and a string str, find if str follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

// Examples:
// pattern = "abba", str = "dog cat cat dog" should return true.
// pattern = "abba", str = "dog cat cat fish" should return false.
// pattern = "aaaa", str = "dog cat cat dog" should return false.
// pattern = "abba", str = "dog dog dog dog" should return false.
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.



/**
 * 重要, 看注释
 * 学习string的一些常用函数
 */


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char> str_mp;
        unordered_map<char, string> char_mp;
        
        string::size_type begin = 0;
        string::size_type len= str.find(" ", begin);
        
        // 判断str有没有空格, 如果没有, pattern是不是只有一个
        if(len == string::npos && pattern.size() == 1)
            return true;
        else if(len == string::npos)
            return false;
        
        for(string::size_type pos = 0; pos < pattern.size(); ++pos) {
            
            string word = str.substr(begin, len-begin);         // substr(pos, length=npos)也能返回最后一个单词
            //cout << word << endl;
            
            // 判断str_mp
            if(str_mp[word] != pattern[pos] && str_mp[word] != 0)  // 存在
                    return false;
            // 判断char_mp
            else if(char_mp[pattern[pos]] != word && char_mp[pattern[pos]] != "")
                return false;
            
            // 更新mp
            str_mp[word] = pattern[pos];
            char_mp[pattern[pos]] = word;
            
            begin = len + 1;
            len = str.find(" ", begin);
            // cout << begin << " : " << len << endl;
        }
        
        
        // 上述循环是pattern主导的, str单词数量可能大于pattern字符数量
        len = str.find_last_of(" ");
        // cout << begin << " : " << len << endl;
        return begin > len && len != string::npos ? false : true;
    }
};