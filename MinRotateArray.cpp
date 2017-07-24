/*
 * 查找旋转数组中最小的数 
 */

#include <exception>
#include <cassert>
#include <iostream>

int MinInRotateArray(int data[], int length)
{
    if (data == nullptr || length <= 0)
    {
        throw new std::exception("Invalid parameters.");
    }

    // 指向前半部分排序数组的指针
    int index1 = 0;
    // 指向后半部分排序数组的指针
    int index2 = length - 1;
    // 所查找的最终结果
    int indexMid = index1;      // 将indexMid初始化为index1，可以解决整个数组有序的情况

    while (data[index1] >= data[index2])
    {
        if (index2 - index1 == 1)
        {
            indexMid = index2;
            return data[indexMid];
        }

        indexMid = (index1 + index2) / 2;

        // 如果index1和index2, indexMid的数字相等，无法快速查找，只能遍历
        if (data[index1] == data[index2] && data[index1] == data[indexMid])
        {
            int result = data[index1];
            for (int i = index1 + 1; i <= index2; ++i)
            {
                if (data[i] < result)
                {
                    result = data[i];
                }
            }
            return result;
        }

        
        // 说明indexMid位于后面的排序数组中，所以结果在index1和indexMid中间
        if (data[indexMid] <= data[index2])
        {
            index2 = indexMid;
        }
        // 说明indexMid位于前面的排序数组中，所以结果在indexMid和index2中间
        else if (data[indexMid] >= data[index1])
        {
            index1 = indexMid;
        }
    }
    return data[indexMid];

}

static void TestUnit()
{
    int data1[] = { 4,5,6,1,2,3 };
    int data2[] = { 1,2,3,4,5,6 };
    int data3[] = { 1,0,0,1,1,1 };
    int data4[] = { 1,1,1,1,0,1 };

    std::cout << "Start to test...\n";
    int length = sizeof(data1) / sizeof(int);
    std::cout << MinInRotateArray(data1, length) << std::endl;
    assert(MinInRotateArray(data1, length) == 1);
    std::cout << "data1 test pass!\n";
    assert(MinInRotateArray(data2, length) == 1);
    std::cout << "data2 test pass!\n";
    assert(MinInRotateArray(data3, length) == 0);
    std::cout << "data3 test pass!\n";
    assert(MinInRotateArray(data4, length) == 0);
    std::cout << "data4 test pass!" << std::endl;
}

static int main_t()
{
    TestUnit();
    getchar();
    return 0;
}