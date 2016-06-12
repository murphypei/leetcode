// Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
// For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
// Note: you may assume that n is not less than 2.

// Hint:
// There is a simple O(n) solution to this problem.
// You may check the breaking results of n ranging from 7 to 10 to discover the regularities.

// 思路很简单，当n > 4，比如5的时候，需要从n中分出一个3出来，用3去乘sum比较大
// 为什么要>4呢，因为n=4的时候，分出3，还剩1，相当于乘以3，所以比较小。


class Solution {
public:
    int integerBreak(int n) {
        int r = 1;
        int sum = 1;
        
        if( n < 2) {
            return 0;
        }
        else if(n == 2){
            return 1;
        }
        else if( n < 5 ) {
            while(n > 2) {
                sum = sum * 2;
                n = n - 2;
            }
            
            sum = sum * n;
            
            return sum;
        }
        
        while(n > 4 ) {
            sum = sum * 3;
            n = n - 3;
        }
        sum = sum * n;
        return sum;
    }
};