/**
You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.
*/


// 两个人轮流拿石头，每个人每次可以拿1-3个，最后一次把所有的石头拿走的人胜利

// 思路：最后能一次拿走，那么最后一次拿走的就是1、2、3个石头中的一种，而倒数第二个人如果不想最后一个人赢，那么他必须剩余4个石头（不多也不能少）
// 加入对方先拿，如果当前石头的总数是4的整数倍，而对方先拿，则不论对方拿几个，我都可以拿4-n个，使石头的总数还是4的倍数，则最后我一定获胜。
// 而如果不是4的整数倍，对方可以拿走m个，使变成4的整数倍，则我开始拿，那么我一定输（两个人同样聪明）

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if(n % 4 == 0) {
        cout << "I win" << endl;
    }
    else {
        cout << "I lose" << endl;
    }

    getchar();
    return 0;
}

