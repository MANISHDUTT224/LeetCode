class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n=nums.size();
        stack<pair<int,int>>st;
        int ans=-1;
        for(int i=n-1;i>=0;i--){
            int cnt=0;
            while(!st.empty() && nums[i]>st.top().first){
                cnt=max(cnt+1,st.top().second);
                st.pop();
            }
            ans=max(ans,cnt);
            st.push({nums[i],cnt});
        }
        return ans;
    }
};