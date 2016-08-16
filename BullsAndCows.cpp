// leetcode:猜字游戏

class Solution {
public:
    string getHint(string secret, string guess) {
        // count每一位(0~9)表示0~9的统计个数
        vector<int> count(10);
        int bulls = 0;
        int cows = 0;
        for(string::size_type i = 0; i < secret.size(); ++i) {
            if(secret[i] == guess[i])
                ++bulls;
            else {
                ++count[secret[i] - '0'];
                if(count[secret[i] - '0'] <= 0) {
                    ++cows;
                }

                --count[guess[i] - '0'];
                if(count[guess[i] - '0'] >= 0) {
                    ++cows;
                }
            }
        }

        streamstring ss;
        string result;
        ss << bulls << "A" << cows << "B";
        ss >> result;
        return result;
    }
}