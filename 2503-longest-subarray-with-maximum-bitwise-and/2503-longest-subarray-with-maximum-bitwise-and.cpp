class Solution {
public:
    static int longestSubarray(vector<int>& nums) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int m=max_element(nums.begin(),nums.end())-nums.begin();
        int x=nums[m];
        const int n=nums.size();
        int maxlen=0;
        for(int i=m;i<n;i++){
            int len=0;
            while(i<n && nums[i]==x){
                i++;
                len++;
            }
            maxlen=max(len,maxlen);
        }
        return maxlen;
    }
};