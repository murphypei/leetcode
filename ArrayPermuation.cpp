/**
 * 利用DFS求数组的全排列
 */

#include <vector>
#include <iostream>
#include <iterator>
#include <memory>

using namespace std;

class Solution {
private:
    vector<vector<int>> perm;
    
public:

    void dfs(vector<int> &nums, vector<int> &visited, vector<int> &index_result, int &cnt) {
        if(cnt == nums.size()) {
            perm.push_back(index_result);
        }
        for(int i = 0; i < nums.size(); ++i) {
            cout << "**" << i << "**" << endl;
            if(visited[i] == 0) {
                visited[i] = 1;
                index_result.push_back(i);
                cnt++;
                dfs(nums, visited, index_result, cnt);
                index_result.pop_back();
                visited[i] = 0;
                cnt--;
            }
        }
    }

    vector<vector<int>> permuation(vector<int> &nums) {
        if(nums.empty()) {
            return perm;
        }

        vector<int> visited(nums.size());
        vector<int> index_result;
        int cnt = 0;
        dfs(nums, visited, index_result, cnt);

        return perm;
    }
};

int main() {
    vector<int> nums = {1, -1, 3, 2, 4};
    shared_ptr<Solution> sptr = make_shared<Solution>();
    auto result = sptr->permuation(nums);
    for(auto &res : result) {
        std::copy(res.cbegin(), res.cend(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    cout << result.size() << endl;

    getchar();
    return 0;
}