class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int lesserI=0,greaterI=n-1;
        vector<int>ans(n);
        for(int i=0,j=n-1;i<n;i++,j--){
            if(nums[i]<pivot){
                ans[lesserI]=nums[i];
                lesserI++;
            }
            if(nums[j]>pivot){
                ans[greaterI]=nums[j];
                greaterI--;
            }
        }
        while(lesserI<=greaterI){
            ans[lesserI]=pivot;
            lesserI++;
        }
        return ans;
    }
};