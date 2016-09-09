// Reverse bits of a given 32 bits unsigned integer.

// For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

// Follow up:
// If this function is called many times, how would you optimize it?


#include <iostream>
#include <stdint.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        uint32_t mask = 1;

        int length = sizeof(uint32_t) * 8;
        int i = 0;
        while(i < length) {
            if(n & mask) {
                result = result << 1;
                result = result | 1;
            }
            else {
                result = result << 1;
            }
            mask = mask << 1;
            ++i;
                
        }
        return result;
    }
};


int main() {
    uint32_t i = 1;
    Solution s;
    cout << s.reverseBits(i) << endl;
}