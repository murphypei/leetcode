// Implement the following operations of a stack using queues.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// empty() -- Return whether the stack is empty.
// Notes:
// You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
// Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
// You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).


/**
 * 用队列来模拟栈操作
 * 同样使用两个队列：保证一个队列为空, 另一个队列来承载元素, 但通过与空队列配合, 使其元素顺序和栈类似, 而和队列相反
 */

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {              // 核心部分, 将元素添加到空队列, 然后再将另一个队列元素搬移过来, 这样就模拟了栈的存储, 队首就是栈顶
        if(q1.empty()) {
            q1.push(x);
            while(!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else {
            q2.push(x);
            while(!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }


    // Removes the element on top of the stack.
    void pop() {
        if(q1.empty())
            q2.pop();
        else
            q1.pop();
    }

    // Get the top element.
    int top() {
        if(q1.empty())
            return q2.front();
        else
            return q1.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }

private:
    queue<int> q1;
    queue<int> q2;
    
};