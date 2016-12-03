// Assume you are an awesome parent and want to give your children some cookies. 
// But, you should give each child at most one cookie. 
// Each child i has a greed factor gi, which is the minimum size of a cookie 
// that the child will be content with; and each cookie j has a size sj. 
// If sj >= gi, we can assign the cookie j to the child i, and the child i will be content. 
// Your goal is to maximize the number of your content children and output the maximum number.

// Note:
// You may assume the greed factor is always positive. 
// You cannot assign more than one cookie to one child.

// Example 1:
// Input: [1,2,3], [1,1]

// Output: 1

// Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
// And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
// You need to output 1.
// Example 2:
// Input: [1,2], [1,2,3]

// Output: 2

// Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
// You have 3 cookies and their sizes are big enough to gratify all of the children, 
// You need to output 2.



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