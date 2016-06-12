// Given an integer, write a function to determine if it is a power of three.

// Follow up:
// Could you do it without using any loop / recursion?


class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        double log_res = log10(n) / log10(3);
        double result = log_res - (int)log_res;
        if(result > 1e-15)
            return false;
        else
            return true;
        
    }
};