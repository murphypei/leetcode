/**
 * 字符串中包含几个部分
 * 连续的不包含空格的子串就组成一部分
 */
 
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        s.push_back(' ');
        for(int i = 1; i < s.size(); ++i)
          if(s[i] == ' ' && s[i-1] != ' ') ++res;
        return res;
    }
};
