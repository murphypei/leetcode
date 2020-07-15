#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int index = 0;
        while (!strs.empty() && true)
        {
            int i = 0;
            for (; i < strs.size(); ++i)
            {
                if (strs[i].size() <= index)
                {
                    break;
                }
                if (strs[i][index] != strs[0][index])
                {
                    break;
                }
            }
            if (i >= strs.size())
            {
                index++;
            }
            else
            {
                break;
            }
        }
        return strs.empty() ? string{} : strs[0].substr(0, index);
    }
};