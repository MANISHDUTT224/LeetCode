class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        set<int>st;
        int  i=0;
        if(nums.size()==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int longest=1;
        for(int it:st){
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