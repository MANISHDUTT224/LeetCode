class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>res;
        set<int>temp1;
        for(int i=0;i<nums1.size();i++){
            if(find(nums2.begin(),nums2.end(),nums1[i])==nums2.end()){
                temp1.insert(nums1[i]);
            }
        }
        vector<int>t1(temp1.begin(),temp1.end());
        res.push_back(t1);
        set<int>temp2;
        for(int i=0;i<nums2.size();i++){
            if(find(nums1.begin(),nums1.end(),nums2[i])==nums1.end()){
                temp2.insert(nums2[i]);
            }
        }
        vector<int>t2(temp2.begin(),temp2.end());
        res.push_back(t2);
        return res;
    }
};