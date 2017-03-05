// Given a word, you need to judge whether the usage of capitals in it is right or not.

// We define the usage of capitals in a word to be right when one of the following cases holds:

// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital if it has more than one letter, like "Google".
// Otherwise, we define that this word doesn't use capitals in a right way.
// Example 1:
// Input: "USA"
// Output: True
// Example 2:
// Input: "FlaG"
// Output: False
// Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.



class Solution {
public:
    bool detectCapitalUse(string word) {
        auto it = word.cbegin();
    
        // 第一个字符是小写的，后面必须都是小写
        if (islower(*it)) {
            while(++it != word.cend()) {
                if(!islower(*it)) {
                    //cout << *it << endl;
                    return false;
                }
            }
            return true;
        }
        else {   // 如果第一个字符是大写，后面的字符和第二个字符保持一致
            auto second = ++it;
            while(++it != word.cend() && second != word.cend()) {
                //cout << "*it: " << *it << "  (it-1): " << *(it-1) << endl;
                if(islower(*it) != islower(*second)) {
                    return false;
                }
            }
            return true;
        }
    }

};