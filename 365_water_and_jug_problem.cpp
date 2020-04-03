#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>

class Solution
{
public:
    // 对于每时每刻，我们可以记录 A B 两个壶的水量（状态），下一时间就是 6 中可能操作，我们可以用 BFS
    // 遍历这些操作，然后得到当前状态在不同操作后的下一状态，直到结束。 操作总共有 倒满 A/B，倒空 A/B，A 倒入 B，B 倒入
    // A 六种方法
    bool canMeasureWater(int x, int y, int z)
    {
        if (x + y < z)
        {
            return false;
        }

        // 保存 BFS 的节点，节点表示 x 和 y 的水量
        std::queue<std::pair<int, int>> q;

        // 保存已经遍历过的 BFS 节点
        std::unordered_set<std::pair<int, int>, pair_hash> traversed;
        // 初始节点
        q.push(std::pair<int, int>{0, 0});

        // BFS
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            if (p.first + p.second == z)
            {
                return true;
            }
            // 遍历 6 中可能操作，加入队列
            for (int i = 0; i < 6; ++i)
            {
                auto state = this->nextState(p, i, x, y);
                // 遍历过的状态就不用再遍历了
                if (traversed.find(state) != traversed.end())
                {
                    continue;
                }
                else // 否则记录遍历过的状态，并将其加入待遍历的队列中
                {
                    traversed.insert(state);
                    q.push(state);
                }
            }
        }
        return false;
    }

    std::pair<int, int> nextState(const std::pair<int, int> &cur, int type, int x, int y)
    {
        int move = 0;
        switch (type)
        {
        case 0: // 倒满 A
            return std::pair<int, int>{x, cur.second};
        case 1: // 倒满 B
            return std::pair<int, int>{cur.first, y};
        case 2: // 倒空 A
            return std::pair<int, int>{0, cur.second};
        case 3: // 倒空 B
            return std::pair<int, int>{cur.first, 0};
        case 4: // A 倒入 B
            move = std::min(cur.first, y - cur.second);
            return std::pair<int, int>{cur.first - move, cur.second + move};
        case 5: // B 倒入 A
            move = std::min(cur.second, x - cur.first);
            return std::pair<int, int>{cur.first + move, cur.second - move};
        }
        return std::pair<int, int>{0, 0};
    }

    // 简单的 hash 函数，用于为每对 int 生成一个唯一的 key，方便排除已遍历节点
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator()(std::pair<T1, T2> const &pair) const
        {
            std::size_t h1 = std::hash<T1>()(pair.first);
            std::size_t h2 = std::hash<T2>()(pair.second);
            return h1 ^ h2;
        }
    };
};

int main()
{
    Solution s;
    std::cout << s.canMeasureWater(2, 6, 5) << std::endl;
}