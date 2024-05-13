class MyQueue {
public:
    // must implement queue using two stacks
    stack<int> stk_one; // this is used as a stack
    stack<int> stk_two; // used as a queue

    MyQueue() {
    }
    
    void push(int x) {
        while (!stk_two.empty()) {
            stk_one.push(stk_two.top());
            stk_two.pop();
        }
        stk_one.push(x);
    }
    
    int pop() {
        while (!stk_one.empty()) {
            stk_two.push(stk_one.top());
            stk_one.pop();
        }
        int res = stk_two.top();
        stk_two.pop();
        return res;
    }
    
    int peek() {
        while (!stk_one.empty()) {
            stk_two.push(stk_one.top());
            stk_one.pop();
        }
        return stk_two.top();
    }
    
    bool empty() {
        return stk_one.empty() && stk_two.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */