class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stack;
        stack.push(-1);
        int ma=0;
        for(int i=0;i<heights.size();i++){
            while(stack.top()!=-1 && heights[i]<=heights[stack.top()]){
                int height=heights[stack.top()];
                stack.pop();
                int width=i-stack.top()-1;
                ma=max(ma,height*width);
            }
            stack.push(i);
        }
        while(stack.top()!=-1){
            int height=heights[stack.top()];
            stack.pop();
            int width=heights.size()-stack.top()-1;
            ma=max(ma,height*width);
        }
        return ma;
    }
};