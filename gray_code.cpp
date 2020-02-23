#include <bitset>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> result;
        dfs("", 0, n, result);
        return result;
    }

    // 如果当前二进制是 0 那下一个分支就是 0, 1
    // 如果当前二进制是 1 那下一个分支就是 1, 0
    void dfs(string bits, int flag, int n, vector<int> &result)
    {
        if (bits.size() == n)
        {
            if (bits.empty())
            {
                result.push_back(0);
            }
            else
            {
                result.push_back(stoi(bits, 0, 2));
            }
        }
        else if (flag == 0)
        {
            bits.push_back('0');
            dfs(bits, 0, n, result);
            bits.pop_back();
            bits.push_back('1');
            dfs(bits, 1, n, result);
        }
        else
        {
            bits.push_back('1');
            dfs(bits, 0, n, result); // 当前 flag 是 1，然后追加的也是 1，则下一位应该是从 0 开始变化，这里要注意。
            bits.pop_back();
            bits.push_back('0');
            dfs(bits, 1, n, result);
        }
    }
};