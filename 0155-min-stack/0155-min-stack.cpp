class MinStack {
public:
    stack<pair<int,int>> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        pair<int,int> p;
        p.first=val;
        if(!stk.empty())
        {
            if(val<stk.top().second)
            {
                p.second=val;
            }
            else
            {
                p.second=stk.top().second;
            }
        }
        else
        p.second=val;
        
        stk.push(p);
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */