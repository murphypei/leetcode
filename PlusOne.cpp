// Given a non-negative number represented as an array of digits, plus one to the number.

// The digits are stored such that the most significant digit is at the head of the list.


/**
 * 思路：从数组的最后一位开始加1, 需要考虑进位, 如果第[0]位大于9, 则插入首位.
 */

 #include <iostream>
 #include <vector>
 #include <cstdio>

 using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty()) {
            digits.push_back(1);
            return digits;
        }
        
        int cnt = 0;
        digits[digits.size()-1]++;
        
        for(size_t i = digits.size() - 1; i > 0; --i) {
            if(digits[i] > 9) {
                digits[i] = 0;
                cnt = 1;
            }
            else {
                cnt = 0;
                break;
            }
            digits[i-1] = digits[i-1] + cnt;
            cout << i-1 << " : " << digits[i-1] << endl;
        }
            
        if(digits[0] > 9) {
            digits[0] = 0;
                digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};


int main() {
    cout << "hello world" << endl;
    getchar();
    return 0;
}