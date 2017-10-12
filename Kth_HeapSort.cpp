/**
 * n个数中找第k小的数: 维持一个k的堆排序，然后每次从剩余的n-k中拿出一个数，如果比k的最大数小，则删除k的最大数，然后插入这个数
 * 涉及堆排序的调整，删除和插入
 */

// 使用STL的multiset实现，因为set本身是排序的

#include <set>
#include <iostream>
#include <vector>
#include <functional>
#include <iterator>

using namespace std;

// 维持一个最大堆（greater从大到小排序）
using IntSet = multiset<int, greater<int>>;   

void kth(const vector<int> &nums, IntSet& leastNumbers, int k) {
    leastNumbers.clear();
    if(k < 1 || nums.size() < k) {
        return;
    }

    for(auto nums_it = nums.cbegin(); nums_it != nums.cend(); ++nums_it) {
        if(leastNumbers.size() < k) {
            // 不足k的时候直接插入到set中
            leastNumbers.insert(*nums_it);
        } else {    
            // 进行替换调整
            auto set_it = leastNumbers.begin();
            if(*set_it > *nums_it) {
                leastNumbers.erase(set_it);
                leastNumbers.insert(*nums_it);
            }
        }
    }
}

int main() {
    vector<int> vec{9, 8, 7, 6, 10, 20, 5, 4, 3, 2, 11, 1};
    int k;
    cin >> k;

    IntSet leastNumbers;
    kth(vec, leastNumbers, k);

    std::copy(leastNumbers.begin(), leastNumbers.end(), ostream_iterator<int>(cout, " "));

    return 0;
}
    