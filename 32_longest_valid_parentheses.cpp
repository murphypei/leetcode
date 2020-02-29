#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        // 栈中存放的是左括号的下标
        stack<int> st;
        int start = 0;
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                // 遇到左括号，将当前下标压入栈（而不是括号字符）。
                st.push(i);
            }
            else // ')'
            {
                if (st.empty())
                {
                    // start 是防止连续被抵消导致的记录长度变短的情况。
                    start = i + 1;
                }
                else
                {
                    // 右括号抵消了一个左括号的下标
                    st.pop();
                    // 如果栈中没有左括号的下标了，说明匹配上了，求长度，这里就必须用 start
                    // 了，因为栈中的左括号下标不一定是起始的。
                    if (st.empty())
                    {
                        res = std::max(res, i - start + 1);
                    }
                    // 如果栈中还有左括号的下标，说明被抵消了一个，还有剩余的。
                    else
                    {
                        res = std::max(res, i - st.top());
                    }
                }
            }
        }
        return res;
    }
};