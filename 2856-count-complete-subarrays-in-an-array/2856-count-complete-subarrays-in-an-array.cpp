class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int res=0;
        unordered_map<int,int>cnt;
        unordered_set<int>distinct(nums.begin(),nums.end());
        int n=nums.size(),distinct_count=distinct.size(),right=0;
        for(int left=0;left<n;left++){
            if(left>0){
                int remove=nums[left-1];
                cnt[remove]--;
                if(cnt[remove]==0){
                    cnt.erase(remove);
                }
            }
            
            while(right<n && cnt.size()<distinct_count){
                int add=nums[right];
                cnt[add]++;
                right++;
            }
            if(cnt.size()==distinct_count){
                res+=(n-right+1);
            }
            
        }
        return res;
    }
};