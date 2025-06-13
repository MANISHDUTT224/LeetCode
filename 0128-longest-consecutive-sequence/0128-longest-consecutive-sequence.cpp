class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        set<int>st;
        for(int num:nums){
            st.insert(num);
        }
       int longest=0;
    for(int num:st)
    {
       
        if(st.find(num-1)==st.end()){
             int length=1;
            while(st.find(num+length)!=st.end()){
                length++;
            }
            longest=max(length,longest);
        }
    
    }
    return longest;
    }
};