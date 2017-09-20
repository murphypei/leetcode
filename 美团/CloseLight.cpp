/**
 * 一排灯泡，初始状态有开有闭（1或者0表示），现在进行如下操作：
   * Alice首先操作，然后两个人轮流
   * 轮到操作的人，需要选择一个点亮的灯泡，然后把这个灯泡熄灭，以及其右边的所有灯泡的状态改变
* 如果一个人操作完了之后，所有的灯泡熄灭了，则这个人赢了。
*/

// 思路：博弈论的思路：不管alice和bob做了什么操作，最后一位肯定是要 0 1 之间来回变换的。 
// 所以只有能把1变成0的人，才是最后的胜利者。 所以只需要判断最后一位输入是1，就是alice赢，最后一位是0，就是bob赢。


#include <iostream>

using namespace std;

int main() {
    int n;
    while(cin >> n) {
        int nums[n];
        for(int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        if(nums[n - 1] == 1) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }
    return 0;
}