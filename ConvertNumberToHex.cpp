/**
 * 十进制转为十六进制
 */
 
class Solution {
public:
    string toHex(int num) {
        string res;
        // 因为是int，所以最多32位
        for(int i = 0; num && i < 32 / 4; ++i)
        {
            // 取后4位
            int tmp = num & 0xf;
            if(tmp >= 10)
            {
                res.insert(res.begin(), static_cast<char>('a' + tmp - 10));
            }
            else
            {
                res.insert(res.begin(), static_cast<char>('0' + tmp));
            }
            
            num >>= 4;
        }
        return res.empty() ? "0" : res;
    }
};