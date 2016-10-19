// Binary Watch
// A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

// Each LED represents a zero or one, with the least significant bit on the right.

// For example, the above binary watch reads "3:25".

// Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

// Example:

// Input: n = 1
// Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
// Note:
// The order of output does not matter.
// The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
// The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".



// 组合问题

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        
        vector<vector<int> > hour(5), min(7);   // vector存放置1的个数及其不同组合位index(因为位数为0~4和0~6，所以长度为5和7)
        for(int i=0; i<12; ++i) {               // i表示小时数
            int n = bitset<4>(i).count();       // 以i来初始化bitset，取出其置1的位数
            hour[n].push_back(i);               // 以置1的位数作为索引，元素是不同小时数组成的vector
        }
        for(int i=0; i<60; ++i) {
            int n = bitset<6>(i).count();
            min[n].push_back(i);
        }
        
        vector<string> res;

        if(num < 0 || num > 10)
            return res;
        for(int i=0; i <= num && i <= 4; ++i) {             // hour置1的位数
            for(int j=0; j < hour[i].size(); ++j){          // 对于hour中i位置1的vector，取出每一个元素
                for(int k=0; num-i <= 6 && k < min[num-i].size(); ++k) {        // 取出min中num-i位置1的元素
                    // 拼接字符串
                    string str = to_string(hour[i][j]) + ":";
                    if(min[num-i][k] < 10)
                        str += "0";
                    str += to_string(min[num-i][k]);
                    res.push_back(str);
                }
            }
        }
        
        return res;
        ;
    }
};