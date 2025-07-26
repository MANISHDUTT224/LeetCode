class Solution {
    public int largestRectangleArea(int[] arr) {
        Stack<Integer> stack = new Stack<>();
        int n = arr.length;
        int maxArea = 0;
        if(arr.length==1){
            return arr[0];
        }
        for(int index = 0; index <= n; index++) {
            int element = (index == n) ? 0 : arr[index];
            while(!stack.isEmpty() && arr[stack.peek()] > element) {
                int height = arr[stack.pop()];
                int previousSmaller = (stack.isEmpty()) ? -1 : stack.peek();
                int width = index - previousSmaller - 1;
                maxArea = Math.max(maxArea, height * width);
            }
            stack.push(index);
        }
        return maxArea;
    }
}