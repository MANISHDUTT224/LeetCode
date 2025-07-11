class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left(height.size(),0);
        vector<int>right(height.size(),0);
        left[0]=height[0];
        int trapped=0;
        right[height.size()-1]=height[height.size()-1];
        for(int i=1;i<height.size();i++){
            left[i]=max(left[i-1],height[i]);
        }
        for(int i=height.size()-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        for(int i=0;i<height.size();i++){
            int waterlevel=min(left[i],right[i]);
            trapped+=(waterlevel-height[i]);
        }
        return trapped;
    }
};