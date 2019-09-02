#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        dfs(result, n, n, "");
        return result;
    }

    /**
     * left 和 right 是剩余还没用的左右括号的数量
     */
    void dfs(vector<string> &result, int left, int right, string s)
    {
        if (left == 0 && right == 0)
        {
            result.emplace_back(s);
            return;
        }
        if (left > 0)
        {
            dfs(result, left - 1, right, s + "(");
        }
        // 未使用的右括号数量必须大于左括号的数量才能保证形式正确
        if (right > 0 && right > left)
        {
            dfs(result, left, right - 1, s + ")");
        }
    }
};
