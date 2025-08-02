class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1,area,maxa;
        while(left<right){
           area=(right-left)*min(height[left],height[right]);
           if(maxa<area){
            maxa=area;
           }
           if(height[left]<height[right]){
            left++;
           }
           else{
            right--;
           }
        }
        return maxa;
    }
};