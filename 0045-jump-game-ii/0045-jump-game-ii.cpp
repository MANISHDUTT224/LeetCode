class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jumps=0,curfarthest=0,curend=0;
        for(int i=0;i<n-1;i++){
            curfarthest=max(curfarthest,i+nums[i]);
            if(i==curend){
                curend=curfarthest;
                jumps++;
            }
        }
        return jumps;
    }
};