#include <iostream>
#include <string>
#include <stack>

using namespace std;

int calc(int num1, int num2, char op) {
    if(op == '|') {
        return num1 | num2;
    } else if(op == '&') {
        return num1 & num2;
    }
    return 0;
}

int calcExpr(string expr) {
    stack<int> nums;
    stack<char> ops;
    for(int j = 0; j < expr.size(); ++j) {
        char ch = expr[j];
        if(isdigit(ch)) {
            nums.push(ch - '0');
        } else {
            if(ch == '(' | ch == '|' | ch == '&' ) {
                ops.push(ch);
            } else if (ch == ')') {
                char op = ops.top();
                ops.pop();
                ops.pop();
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                int r = calc(num1, num2, op);
                nums.push(r);
            }
        }
    }
    return nums.top();
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        string expr;
        cin >> expr;
        stack<int> nums;
        stack<char> ops;
        for(int j = 0; j < expr.size(); ++j) {
            char ch = expr[j];
            if(isdigit(ch)) {
                nums.push(ch - '0');
            } else {
                if(ch == '(' | ch == '|' | ch == '&' ) {
                    ops.push(ch);
                } else if (ch == ')') {
                    char op = ops.top();
                    ops.pop();
                    ops.pop();
                    int num1 = nums.top();
                    nums.pop();
                    int num2 = nums.top();
                    nums.pop();
                    int r = calc(num1, num2, op);
                    nums.push(r);
                }
            }
        }
        cout << nums.top() <<" " << -1 << endl;
    }

    return 0;
}