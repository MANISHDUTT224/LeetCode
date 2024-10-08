class Solution {
public:
    int findpos(int ele,vector<int>&ans){
        for(int i=0;i<ans.size();i++){
            if(ans[i]==ele){
                return i;
            }
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        int i=0,j=0;
        while(i<nums1.size()){
            int posmatch=findpos(nums1[i],nums2);
            if(posmatch==-1){
                res.push_back(-1);
            }
            int flg=0;
            for(int k=posmatch;k<nums2.size();k++){
                if(nums2[k]>nums2[posmatch]){
                    res.push_back(nums2[k]);
                    flg=1;
                    break;
                }
            }
            if(flg==0){
                res.push_back(-1);
            }
            i++;
        }
        return res;
    }
};