class MinStack {
public:
    vector<int> stack;
    vector<int> minStack;
    MinStack(){
    }
    
    void push(int value) {
        stack.push_back(value);

        if(minStack.empty()){
            minStack.push_back(value);
        } else{
            minStack.push_back(min(value,minStack.back()));
        }
    }
    
    void pop() {
        stack.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        return stack[stack.size() - 1];
    }
    
    int getMin() {
        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */