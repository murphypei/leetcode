// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

// The replacement must be in-place, do not allocate extra memory.

// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        int n = nums.size() - 1;
        
        // 从后往前，找到破坏降序（最不可能情况）的元素索引
        while( n > 0 && nums[n] <= nums[n-1])        // 降序条件
            n--;

        // 如果输入是已经排好序的升序序列，则只需要交换后两个数
        if(n == nums.size() - 1)  
        {
            swap(nums[n], nums[n-1]);
            return;
        }
        
        // 如果输入是已经排好序的降序，则循环，结果为升序序列
        if(n == 0)
        {
            std::reverse(nums.begin(), nums.end());
            return;
        }
        
        // 其余情况，将n赋值
        n--;
        
        // 从后往前，找到比破坏元素大的第一个数
        for(vector<int>::iterator iter = nums.end(); iter != nums.begin();)
        {
            iter--;
            if(*iter > nums[n])    
            {
                // 交换这两个元素
                swap(*iter, nums[n]);
                // 将破坏元素到末尾的序列逆序（降序变增序）
                std::reverse(nums.begin() + n + 1, nums.end());
                break;
            }
        }
    }
    
    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
};