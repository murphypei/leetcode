/**
 * 寻找两个列表中共有的元素，如果有多个共有的元素，则返回元素在两个列表中下标之和最小的元素
 */

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> result;
        int leastIdxSum = INT_MAX;
        unordered_map<string, int> mp;
        for(int i = 0; i < list1.size(); ++i)
        {
            mp[list1[i]] = i;
        }
        
        for(int i = 0; i < list2.size(); ++i)
        {
            if(mp.find(list2[i]) != mp.end())
            {
                int currentSum = i + mp.at(list2[i]);
                if(currentSum < leastIdxSum)
                {
                    if(!result.empty())
                        result.clear();
                    cout << result.size() << endl;
                    leastIdxSum = currentSum;
                    result.push_back(list2[i]);
                }
                else if(currentSum == leastIdxSum)
                {
                    result.push_back(list2[i]);
                }
            }
        }
        
        return result;
    }
};