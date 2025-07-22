class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>seen;
        int left=0,cursum=0,maxsum=0;
        for(int right=0;right<n;right++){
            while(seen.find(nums[right])!=seen.end()){
                cursum-=nums[left];
                seen.erase(nums[left]);
                left++;
            }
            cursum+=nums[right];
            seen.insert(nums[right]);
            maxsum=max(maxsum,cursum);
        }
        return maxsum;
    }
};