#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        auto temp_strs = strs;

        // 对每个字符串内部按字符排序，排序后有重复，但是两个字符串 vector 一一对应。
        for (auto &s : temp_strs)
        {
            std::sort(s.begin(), s.end());
        }

        // 将每个字符串排序后相同的结果进行分组。
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < temp_strs.size(); ++i)
        {
            mp[temp_strs[i]].emplace_back(std::move(strs[i]));
        }

        // 构造结果。
        vector<vector<string>> results;
        for (auto &item : mp)
        {
            results.emplace_back(std::move(item.second));
        }
        return results;
    }
};