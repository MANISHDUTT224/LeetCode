class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=1;
         set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        if(nums.size()==0){
            return 0;
        }
        int cnt,x;
        for(int i=0;i<nums.size();i++){
            
            if(st.find(nums[i]-1)==st.end()){
                 x=nums[i];
                cnt=1;
                while(st.find(x+1)!=st.end()){
                    x++;
                    cnt++;
                }
                 longest=max(cnt,longest);
            }
        }
        return longest;
    }
};