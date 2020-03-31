#include <queue>

class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x)
    {
        // 栈压入的元素应该在队列的第一位，因此需要将队列前面的元素因此放到该元素的后面。
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i)
        {
            // 将队列第一个元素放到最后面。
            int e = q.front();
            q.pop();
            q.push(e);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int e = q.front();
        q.pop();
        return e;
    }

    /** Get the top element. */
    int top() { return q.front(); }

    /** Returns whether the stack is empty. */
    bool empty() { return q.empty(); }

private:
    std::queue<int> q;
};