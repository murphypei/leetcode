// Given a collection of distinct numbers, return all possible permutations.

// For example,
// [1,2,3] have the following permutations:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    
public:
    vector<vector<int>> result;

    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() <= 1)
        {
            result.push_back(nums);
            return result;
        }
        
        dfs(0, nums);
        return result;
    
    }
    
    void dfs(int index, vector<int>& nums)
    {
        if(index == nums.size())
        {
            result.push_back(vector<int>(nums.begin(), nums.end()));
            return;
        }
        
        // 将nums[index] 与后面的每个数交换，然后递归遍历交换之后的序列
        for(int j = index; j < nums.size(); ++j)
        {
            std::swap(nums[j], nums[index]);
            dfs(index+1, nums);  
            std::swap(nums[j], nums[index]);
        }
    }
};

int main(int args, char* argv[])
{

    int i, j;
    int numbers[] = {1,2,3,4};
	vector<int> nums(numbers, numbers + sizeof(numbers) / sizeof(numbers[0]));
	Solution s;
	vector< vector<int> > result = s.permute(nums);

	cout << result.size() << endl;
    for (i = 0; i<result.size(); i++)
    {
        for (j = 0; j<result[i].size(); j++)
        {
            cout << result[i][j] << "  ";
        }
        cout << endl;
    }

	system("pause");
	return 0;
}