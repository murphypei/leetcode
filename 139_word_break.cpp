#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    // 字典树的形式，将每个单词与当前字符串进行前缀匹配，匹配到了就作为分支，向下进行 BFS 搜索。
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // 保存该层字符串的起始位置，用于 BFS。
        queue<int> indexes;
        indexes.push(0);

        // BFS 记录已经访问过的结点。
        vector<bool> visited(s.size(), false);
        visited[0] = true;

        while (!indexes.empty())
        {
            // 对该层每个节点进行搜索（BFS）。
            int levelSize = indexes.size();
            for (int i = 0; i < levelSize; ++i)
            {
                int start = indexes.front();
                indexes.pop();
                for (auto &word : wordDict)
                {
                    auto len = word.size();
                    // 超过长度，该条 BFS 路径结束，转到下一个节点
                    if (start + len > s.size())
                    {
                        continue;
                    }

                    // 正好完全匹配，返回结果
                    if (s.substr(start) == word)
                    {
                        return true;
                    }

                    // 判断符合条件，加入一个新的 BFS 节点（下一层），注意，visited 判断在前可以显著的剪枝。
                    if (!visited[start + len] && s.substr(start, len) == word &&)
                    {
                        indexes.push(start + len);
                        visited[start + len] = true;
                    }
                }
            }
        }
        return false;
    }
};