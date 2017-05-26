/**
 * 给一列数组，输出每个元素对应名次（也就是排序后的位置），前三名给出相应的字符串
 *
 * 巧妙的思路：利用map和set这类容器本身是有序的来解决
 **/

#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
    
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) 
        mp[nums[i]] = i;
    
    vector<string> ans(mp.size(), "");
    int cnt = 1; 

    // 在上面将vector的数存放在map中后，map会按照键值对其进行排序，内部维持一个红黑树

    for (map<int, int>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++, cnt++) {
        if (cnt == 1) 
            ans[it->second] = "Gold Medal";
        else if (cnt == 2) 
            ans[it->second] = "Silver Medal";
        else if (cnt == 3) 
            ans[it->second] = "Bronze Medal";
        else 
            ans[it->second] = to_string(cnt);
    }
    
    return ans;
    }
};