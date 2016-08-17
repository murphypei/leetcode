// Given two strings s and t, determine if they are isomorphic.

// Two strings are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

// For example,
// Given "egg", "add", return true.

// Given "foo", "bar", return false.

// Given "paper", "title", return true.

// Note:
// You may assume both s and t have the same length.


/**
 * 两个等长的字符串相同位置一一对应
 *
 * 因为是字符, 所以可以用数组来实现map
 *
 * 一个map无法确定(因为map的值可以重复, 也就是一个字符串不同位置不同字符可以对应另一字符串相同的字符), 必须用两个map
 */


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int s_array[128] = {0};
        int t_array[128] = {0};
        
        for(string::size_type i = 0; i < s.size(); ++i) {
            if(s_array[s[i]]) {
                if(s_array[s[i]] != t[i])
                    return false;
            }
            else if(t_array[t[i]]) {
                if(t_array[t[i]] != s[i])
                    return false;
            }
            else {  
                s_array[s[i]] = t[i];
                t_array[t[i]] = s[i];
            }
        }
        
        return true;
    }
};