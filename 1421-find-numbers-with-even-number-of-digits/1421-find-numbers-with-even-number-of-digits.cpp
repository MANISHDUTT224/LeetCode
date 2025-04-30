class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int len=0;
        for(int num:nums){
            string strnum=to_string(num);
            len+=(strnum.size()%2==0);
        }
        return len;
    }
};