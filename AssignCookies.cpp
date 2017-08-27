/**
 * 分蛋糕问题：每个人的期望值是数组g，蛋糕是数组s，当分得的s[i] > g[i]时，满足，求最多能让多少人满足
 *
 * 思路：将两个数组排序之后比较
 */

#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        quickSort(g, 0, g.size());
        quickSort(s, 0, s.size());
        size_t i = 0;
        size_t j = 0;
        int cnt = 0;
        while(i < g.size() && j < s.size()) {
            if(s[j] >= g[i]) {
                i++;
                j++;
                cnt++;
            }
            else
                j++;
        }
        return cnt;
    }
    
    void quickSort(vector<int>& vec, size_t beg, size_t end) {
    	// 如果长度为1，则不需要排序
    	if (end - beg <= 1)
    		return;
    
    	// low和high都是直接有效idx
    	size_t low = beg;
    	size_t high = end;	// 类似迭代器的哨兵
    	
    	int key = vec[low];		// 随机选取一个key
    
    	while (low < high) {
    		while (--high > low) {  // 注意high的值
    			if (vec[high] <= key) {
    				swap(vec[high], vec[low]);
    				break;
    			}
    		}
    		
    		while (++low < high) {
    			if (vec[low] >= key) {
    				swap(vec[high], vec[low]);
    				break;
    			}
    		}
    		
    	}
    	// cout << "***"  << low << " " << high << endl;
    	// printVec(vec);
    	// 因为最后操作的是low，所以中间哨兵位置应该在low，low此时指向的key所在位置的后一位
    	quickSort(vec, beg, low);
    	quickSort(vec, low, end);
    }
};