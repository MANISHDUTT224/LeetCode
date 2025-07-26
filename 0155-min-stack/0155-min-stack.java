class MinStack {
    int stack[],minstack[];
    int top;
    public MinStack() {
         stack=new int[100001];
         minstack=new int[100001];
        top=-1;
    }
    
    public void push(int x) {
        stack[++top]=x;
        if(top==0){
            minstack[top]=x;
        }
        else{
            minstack[top]=Math.min(minstack[top-1],x);
        }
    }
    
    public void pop() {
        if(top>=0){
            top--;
        }
    }
    
    public int top() {
        if(top==-1){
            return -1;
        }
        return stack[top];
    }
    
    public int getMin() {
        if(top==-1){
            return -1;
        }
        return minstack[top];
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */