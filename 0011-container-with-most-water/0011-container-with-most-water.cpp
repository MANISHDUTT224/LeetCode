class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1,area,maxarea=INT_MIN;
        while(l<r){
            area=(right-left)*min(height[left],height[right]);
            if(maxa>area){
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