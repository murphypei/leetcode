// iven an index k, return the kth row of the Pascal's triangle.

// For example, given k = 3,
// Return [1,3,3,1].

// Note:
// Could you optimize your algorithm to use only O(k) extra space?

/**
 * 要求了O(k)的空间复杂度, 所以只能在原数组上进行遍历 
 * 因为数的计算公式是a[j] = a[j] + a[j-1], 如果从前向后遍历, a[j-1]在a[j]之前已经改变了, 得不到正确结果
 * 【必须从后向前遍历】
 *
 * 思路仍然是一层层的生成数, 两层循环
 **/


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1);
        result[0] = 1;      // 第一层      

        for(int i = 1; i <= rowIndex; ++i) { // 层数循环
            // 生成i+1层的所有数
            for(int j = i; j >= 0; --j) {
                if(j == 0 && j == i)    // 边缘
                    result[j] = 1;
                else
                    result[j] = result[j] + result[j-1];
            }
        }
    }
}