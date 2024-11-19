class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int>elements;
        long long cursum=0,maxsum=0,begin=0;
        for(int end=0;end<n;end++){
            if(elements.find(nums[end])==elements.end()){
                cursum+=nums[end];
                elements.insert(nums[end]);
                if(end-begin+1==k){
                    maxsum=max(maxsum,cursum);
                    cursum-=nums[begin];
                    elements.erase(nums[begin]);
                    begin++;
                }
            }
            else{
                while(nums[begin]!=nums[end]){
                    cursum-=nums[begin];
                    elements.erase(nums[begin]);
                    begin++;
                }
                begin++;
            }
        }
        return maxsum;
    }
};