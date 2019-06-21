class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() >= 4)
        {
            std::sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 3; ++i)
            {
                if (i > 0 && nums[i] == nums[i - 1])
                {
                    continue;
                }
                threeSum(nums, i + 1, nums.size() - 1, nums[i], target);
            }
        }
        return this->results;
    }

    void threeSum(vector<int> &sorted_nums, int beg, int end, int first, int target)
    {
        if (end - beg >= 2)
        {
            for (int i = beg; i <= end - 2; ++i)
            {
                if (i > beg && sorted_nums[i] == sorted_nums[i - 1])
                {
                    continue;
                }
                twoSum(sorted_nums, i + 1, end, first, sorted_nums[i], target);
            }
        }
    }

    void twoSum(vector<int> &sorted_nums, int beg, int end, int first, int second, int target)
    {
        for (int i = beg, j = end; i < j;)
        {
            if (i > beg && sorted_nums[i] == sorted_nums[i - 1])
            {
                i++;
                continue;
            }
            if (j < end && sorted_nums[j] == sorted_nums[j + 1])
            {
                j--;
                continue;
            }
            if (sorted_nums[i] + sorted_nums[j] + first + second == target)
            {
                results.emplace_back(std::vector<int>{first, second, sorted_nums[i], sorted_nums[j]});
                i++;
                j--;
            }
            else if (sorted_nums[i] + sorted_nums[j] + first + second > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
    }

private:
    std::vector<std::vector<int>> results;
};