class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        int maxlen=0;
        for(int num:nums){
            st.insert(num);
        }
        for(int num:st){
            if(st.find(num-1)==st.end()){
                int len=1;
                while(st.find(num+len)!=st.end()){
                    len++;
                }
                maxlen=max(maxlen,len);
            }
        }
        return maxlen;
    }
};