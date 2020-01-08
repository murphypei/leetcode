#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        size_t sz1 = word1.size(), sz2 = word2.size();
        vector<vector<int>> distance(sz1 + 1, vector<int>(sz2 + 1, 0));
        for (int i = 1; i <= sz1; ++i)
        {
            distance[i][0] = i;
        }
        for (int i = 1; i <= sz2; ++i)
        {
            distance[0][i] = i;
        }
        for (int i = 1; i <= sz1; ++i)
        {
            for (int j = 1; j <= sz2; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    distance[i][j] = distance[i - 1][j - 1];
                }
                else
                {
                    distance[i][j] =
                        std::min(distance[i - 1][j - 1], std::min(distance[i - 1][j], distance[i][j - 1])) + 1;
                }
            }
        }
        return distance[sz1][sz2];
    }
};