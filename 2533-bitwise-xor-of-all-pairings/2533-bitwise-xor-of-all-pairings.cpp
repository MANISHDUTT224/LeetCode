class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1=0,xor2=0,len1=nums1.size(),len2=nums2.size();
        if(len1%2){
            for(int num2:nums2){
                xor2^=num2;
            }
        }
        if(len2%2){
            for(int num1:nums1){
                xor1^=num1;
            }
        }
        return xor1^xor2;

    }
};