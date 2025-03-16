class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>st;
        for(int num:nums){
            st.insert(num);
        }
        if(nums.size()==1){
            return nums[0];
        }
        int su=nums[0];
        for(int i:st){
            if(i==nums[0]){
                continue;
            }
            su=max(su,max(su+i,i));
        }
        return su;
    }
};