/**
 * 从一个数组中随机等概率的等于一个指定target的元素下标
 *
 * 蓄水池抽样法
 */

class Solution {
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int cnt = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if (nums.at(i) == target) {
                if(rand() % (++cnt) == 0) {
                    res = i;
                }
            }
        }
        
        return res;
    }

private:
    vector<int> nums;
};