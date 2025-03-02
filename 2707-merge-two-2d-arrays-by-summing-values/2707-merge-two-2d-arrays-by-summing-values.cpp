class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        vector<vector<int>>res;
        set<int>st;
        for(int i=0;i<nums1.size();i++){
                    bool found=false;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i][0]==nums2[j][0]){
                    nums1[i][1]+=nums2[j][1];
                   
                    res.push_back(nums1[i]);
                    st.insert(nums1[i][0]);
                    found=true;
                    break;
                }
            }
            if(!found){
                res.push_back(nums1[i]);

            }
        }
        for(int i=0;i<nums2.size();i++){
            if(st.find(nums2[i][0])==st.end()){
                res.push_back(nums2[i]);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};