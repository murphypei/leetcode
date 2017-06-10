/**
 * 实现一个最小栈，能够获取栈中当前的最小值
 
 * 思路：利用另一个栈来存储最小值
 */
 
 class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        sk.push(x);
        if(minSk.empty() || x <= minSk.top()) // 这地方一定要有=
            minSk.push(x);
    }
    
    void pop() {
        if(sk.top() == minSk.top())
        {
            minSk.pop();
        }
        sk.pop();
    }
    
    int top() {
        return sk.top();
    }
    
    int getMin() {
        return minSk.top();
    }
private:
    stack<int> sk;
    stack<int> minSk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
