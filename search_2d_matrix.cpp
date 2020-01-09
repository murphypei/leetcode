#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return false;
        }
        int row = matrix.size(), col = matrix[0].size();

        int left = 0, right = row - 1;
        int result_row_index = 0;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (matrix[mid][0] == target)
            {
                return true;
            }
            else if (target > matrix[mid][col - 1])
            {
                left = mid + 1;
            }
            else if (target < matrix[mid][0])
            {
                right = mid - 1;
            }
            else
            {
                result_row_index = mid;
                break;
            }
        }
        left = 0, right = col - 1;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (matrix[result_row_index][mid] == target)
            {
                return true;
            }
            else if (matrix[result_row_index][mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return false;
    }
};