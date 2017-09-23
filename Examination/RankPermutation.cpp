// n个人排名，允许并列名次，共有多少种排名结果？

// 动态规划：https://www.zhihu.com/question/30200444/answer/47212947


#include <iostream>

using namespace std;

typedef long long LL;

void fac(int n) {
    int *fact = new int[n];
    for(int i = 1; i < n; i++) {
        fact[i] = (i == 1 ? 1 : (fact[i-1] * i));
    }

    // for(int i = 0; i < n; ++i) {
    //     cout << i << " : " << fact[i] << endl;
    // }

    int **dp = new int*[n];
    for(int i = 0; i < n; ++i) {
        dp[i] = new int[n];
    }

    int *ans = new int[n];
    for(int i = 1; i < n; ++i) {
        ans[i] = 0;
    }

    for(int i = 1; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            if(i == j) {
                dp[i][j] = fact[i];
            } else if( i == 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = i * dp[i][j-1] + i * dp[i-1][j-1];
            }
        }
    }

    for(int i = 1; i < n; ++i) {
        for(int j = 1; j <= i; ++j) {
            ans[i] += dp[j][i];
        }
    }

    for(int i = 0; i < n; ++i) {
        cout << i << " : " << ans[i] << endl;
    }


    // 释放内存
    delete[] fact;
    delete[] ans;
    for(int i = 0; i < n; ++i) {
        delete[] dp[i];
    }
}

int main() {
    int n = 10;
    fac(n);

    getchar();
    return 0;
}