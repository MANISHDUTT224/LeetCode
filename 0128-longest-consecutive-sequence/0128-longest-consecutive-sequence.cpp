class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        
        int n=nums.size();
        if(n==0){
            return n;
        }
        set<int>st(nums.begin(),nums.end());
        int longest=1;
        for(auto it:nums){
            if(st.find(it-1)==st.end()){
                int len=1;
                while(st.find(it+len)!=st.end()){
                    len++;
                }
                longest=max(longest,len);

            }
        }
        return longest;
    }
};