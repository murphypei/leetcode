/**
 * 一种类似回旋镖形状的三元组结构，要求第一个点和第二个点之间的距离跟第一个点和第三个点之间的距离相等。
 * 现在给了我们n个点，让我们找出能够组成回旋镖的个数。
 *
 * 将每一个点看作是第一个点，第二和第三个点就是到其距离相等的点，通过一次遍历找出这些点，假设有n个，则对于
 * 第一个点来说，就能组成n(n-1)个回旋镖。然后将所有点构成的回旋镖加起来就是最终结果
 */

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        if(points.size() < 3)
        {
            return 0;
        }
        
        int res = 0;
        for(int i = 0; i < points.size(); ++i)
        {
            unordered_map<int, int> distances;
            for(int j = 0; j < points.size(); ++j)
            {
                distances[calcDistance(points[i], points[j])]++;
            }
            
            // 计算点i构成的所有回旋镖数量
            for(auto it = distances.cbegin(); it != distances.cend(); ++it)
            {
                res += it->second *(it->second - 1);   
            }
        }
        
        return res;
    }
    
private:
    int calcDistance(pair<int, int> &a, pair<int, int> &b)
    {
        return pow((a.first - b.first), 2) + pow((a.second - b.second), 2);
    }
};