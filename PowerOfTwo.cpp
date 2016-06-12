// Given an integer, write a function to determine if it is a power of two.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        bitset<32> bnum(n);
        if(bnum.test(bnum.size() - 1 ))
            return false;
        if(bnum.count() > 1 || bnum.count() == 0)
            return false;
        else
            return true;
    }
};