// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty() || s.size() == 1)
            return true;
            
        int low = 0;
        int high = s.size() -1;
        
        while(low <= high) {
            //cout << "low: " << low << "/t high: " << high << endl;
            while(!isalnum(s[low]) && low < high)   // 判断是否是字母或者数字
                ++low;
            while(!isalnum(s[high]) && low < high )
                --high;
                
            //cout << "***low: " << low << "/t high: " << high << endl;
            if(tolower(s[low]) == tolower(s[high])) {       // 都转换成小写来比较
                ++low;
                --high;
            }
            else {
                //cout << " --- FALSElow: " << low << "/t high: " << high << endl;
                return false;
            }
        }
        return true;
    }
    
};