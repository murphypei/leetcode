#include <stack>
#include <vector>

using namespace std;

// 动态规划
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        int n = T.size();
        std::vector<int> diffs(n, 0);
        if (n <= 1)
        {
            return diffs;
        }
        int max = T[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            // 如果当前值是最大值，则为 0
            if (T[i] >= max)
            {
                max = T[i];
                diffs[i] = 0;
            }
            // 如果小于下一个值，则直接为 1
            else if (T[i] < T[i + 1])
            {
                diffs[i] = 1;
            }
            else // 上述不成立，说明当前值大于下一个值，但是后续有值比当前值要大，要找到最近的这个值，计算 diff
            {
                for (int j = i + 1; i < n; ++j)
                {
                    if (T[i] < T[j])
                    {
                        diffs[i] = j - i;
                        break;
                    }
                }
            }
        }
        return diffs;
    }
};

// 栈
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        vector<int> diffs(T.size(), 0);
        stack<int> stk;
        for (int i = 0; i < T.size(); ++i)
        {
            // 栈中都是之前的数，如果之前的数都小于当前值，则更新他们的 diff，然后将其弹出栈，因此栈中的数都是较大的，等待被弹出的。
            while (!stk.empty() && T[stk.top()] < T[i])
            {
                diffs[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return diffs;
    }
};