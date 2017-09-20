/**
小易有一个长度为n的整数序列,a_1,...,a_n。然后考虑在一个空序列b上进行n次以下操作:
1、将a_i放入b序列的末尾
2、逆置b序列
小易需要你计算输出操作n次之后的b序列。 
输入描述:
输入包括两行,第一行包括一个整数n(2 ≤ n ≤ 2*10^5),即序列的长度。
第二行包括n个整数a_i(1 ≤ a_i ≤ 10^9),即序列a中的每个整数,以空格分割。


输出描述:
在一行中输出操作n次之后的b序列,以空格分割,行末无空格。

输入例子1:
4
1 2 3 4

输出例子1:
4 2 1 3
*/

// 思路：不用反转，需要找到规律

#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

vector<int> operate(vector<int> &nums) {
    if(nums.size() <= 1) {
        return nums;
    }
    vector<int> result;
    // 从后往前输出，每次跳两步，奇偶数分开处理
    if(nums.size() % 2 == 0) {
        for(auto it = nums.crbegin(); it != nums.crend(); ++it) {
            result.emplace_back(*it++);
        }
        for(auto it = nums.cbegin(); it != nums.cend(); ++it) {
            result.emplace_back(*it++);
        }
    } else {
        for(auto it = nums.crbegin();; ++it) {
            result.emplace_back(*it++);
            if(it == nums.crend()) {
                break;
            }
        }
        for(auto it = ++(nums.cbegin()); it != nums.cend(); ++it) {
            result.emplace_back(*it++);
        }
    }

    return result;
}

int main() {
    int sz;
    cin >> sz;
    vector<int> nums;
    for(int i = 0; i < sz; ++i) {
        int tmp; cin >> tmp;
        nums.emplace_back(tmp);
    }
    vector<int> result = operate(nums);

    std::copy(result.cbegin(), result.cend(), ostream_iterator<int>(cout, " "));
    cout.flush();

    system("pause");
    return 0;
}

