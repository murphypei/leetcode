#include <vector>

using namespace std;

class Solution
{
public:
    // 非公式解法，常规逻辑思路
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int> result(num_people, 0);

        int num_loop = 0; // 能够完整循环的次数，完整循环完了相当于是 [1, num_people*num_loop]
        while (true)
        {
            int n = num_people * (num_loop + 1);
            if (n * (n + 1) / 2 < candies)
            {
                num_loop++;
            }
            else
            {
                break;
            }
        }

        candies -= (num_loop * num_people) * (num_loop * num_people + 1) / 2;

        // 把每个人完成的次数加上。
        for (int i = 0; i < num_people; ++i)
        {
            // 完整循环中给每个人分配的数量
            result[i] = (i + 1) * num_loop + num_people * (num_loop * (num_loop - 1) / 2);

            // 最后一次非完整循环分配的数量。
            if (candies > 0)
            {
                if (i + 1 + num_loop * num_people <= candies)
                {
                    result[i] += i + 1 + num_loop * num_people;
                    candies -= i + 1 + num_loop * num_people;
                }
                else
                {
                    result[i] += candies;
                    candies = 0;
                }
            }
        }
        return result;
    }
};