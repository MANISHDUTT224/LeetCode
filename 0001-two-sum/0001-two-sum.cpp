class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        vector<pair<int,int>>res;
        for(int i=0;i<n;i++){
            res.push_back({nums[i],i});
        }
        sort(res.begin(),res.end());
        while(l<=r){
            if(res[l].first+res[r].first==target){
                return {res[l].second,res[r].second};
            }
            else if(res[l].first+res[r].first<target){
                l++;
            }
            else{
                r--;
            }
        }
        return {-1,-1};
    }
};