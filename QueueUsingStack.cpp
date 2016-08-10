// Implement the following operations of a queue using stacks.

// push(x) -- Push element x to the back of queue.
// pop() -- Removes the element from in front of queue.
// peek() -- Get the front element.
// empty() -- Return whether the queue is empty.
// Notes:
// You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
// You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).


/**
 * 用栈来实现队列的操作
 * 用两个栈来逆序栈中元素的顺序, 实现FIFO
 */
 
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        in.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(out.empty()) {       // 在out为空的条件下, 将in中的元素全部弹出到out中, 实现元素的逆序
            while(!in.empty()) {
                int top = in.top();
                in.pop();
                out.push(top);
            }
        }
        out.pop();              // 弹出out的栈顶, 也就是in的栈底, 队列的首元素
    }

    // Get the front element.
    int peek(void) {
        if(out.empty()) {       // 在out为空的条件下, 将in中的元素全部弹出到out中, 实现元素的逆序
            while(!in.empty()) {
                int top = in.top();
                in.pop();
                out.push(top);
            }
        }
        return out.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return out.empty() && in.empty();
    }
private:
    stack<int> in;      // push
    stack<int> out;     // pop
};