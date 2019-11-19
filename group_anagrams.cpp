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
        for (auto &s : temp_strs)
        {
            std::sort(s.begin(), s.end());
        }

        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < temp_strs.size(); ++i)
        {
            mp[temp_strs[i]].emplace_back(std::move(strs[i]));
        }

        vector<vector<string>> results;
        for (auto &item : mp)
        {
            results.emplace_back(std::move(item.second));
        }
        return results;
    }
};