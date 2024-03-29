class MyStack {
    queue<int>q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int popValue;
        int newSize=q.size()-1;
        while(newSize--){
            q.push(q.front());
            q.pop();
        }
        popValue=q.front();
        q.pop();
        return popValue;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};