/**
链接：https://www.nowcoder.com/questionTerminal/27f3672f17f94a289f3de86b69f8a25b
来源：牛客网

小易将n个棋子摆放在一张无限大的棋盘上。第i个棋子放在第x[i]行y[i]列。同一个格子允许放置多个棋子。每一次操作小易可以把一个棋子拿起并将其移动到原格子的上、下、左、右的任意一个格子中。小易想知道要让棋盘上出现有一个格子中至少有i(1 ≤ i ≤ n)个棋子所需要的最少操作次数.

输入描述:

输入包括三行,第一行一个整数n(1 ≤ n ≤ 50),表示棋子的个数
第二行为n个棋子的横坐标x[i](1 ≤ x[i] ≤ 10^9)
第三行为n个棋子的纵坐标y[i](1 ≤ y[i] ≤ 10^9)


输出描述:

输出n个整数,第i个表示棋盘上有一个格子至少有i个棋子所需要的操作数,以空格分割。行末无空格

如样例所示:
对于1个棋子: 不需要操作
对于2个棋子: 将前两个棋子放在(1, 1)中
对于3个棋子: 将前三个棋子放在(2, 1)中
对于4个棋子: 将所有棋子都放在(3, 1)中
*/

// 思路：这里是将所有的棋子都移到一个格子中的解答
// 因为求的是移动距离，所以x和y坐标可以分开来考虑，对于任意坐标，要使移动距离之和最短，最佳点必然在给定棋子的某个坐标上（可以反证）

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CalcDistance(vector<int> &coordinate, int x) {
    int sum = 0;
    for(int i = 0; i < coordinate.size(); ++i) {
        sum += std::abs(x - coordinate[i]);
    }
    return sum;
}

int CalcHelper(vector<int> &x, vector<int> &y) {
    vector<int> result(x.size());
    for(int i = 0; i < x.size(); ++i) {
        result[i] = CalcDistance(x, x[i]);
    }
    int minX = *(std::min_element(result.begin(), result.end()));
    for(int i = 0; i < y.size(); ++i) {
        result[i] = CalcDistance(y, y[i]);
    }
    int minY = *(std::min_element(result.begin(), result.end()));

    return minX + minY;

}

int main() {
    
    int N;
    cin >> N;
    vector<int> x_vec(N);
    vector<int> y_vec(N);
    int tmp = 0;

    for(int i = 0; i < N; i++) {
        cin >> tmp;
        x_vec[i] = tmp;
    }

    for(int i = 0; i < N; i++) {
        cin >> tmp;
        y_vec[i] = tmp;
    }
    cout << CalcHelper(x_vec, y_vec);

    getchar();
    return 0;
}