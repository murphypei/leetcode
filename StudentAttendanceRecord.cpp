/**
 * 给定一个字符串，其中L不连续出现超过2次，A不出现超过1次，则返回true，否则返回false
 */

class Solution {
public:
    bool checkRecord(string s) {
        int L = 0, A = 0;
        int continusL = 0;
        
        for(auto &c : s)
        {
            if (c == 'L')
            {
                continusL++;
                if(continusL > 2)
                {
                    return false;
                }
            }
            else
            {
                continusL = 0;   
                if(c == 'A')
                    A++;
            }
        }
        
        return A <= 1;
    }
};