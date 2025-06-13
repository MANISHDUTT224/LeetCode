class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>result;
        for(int i=0;i<nums.size();i++){
            result.push_back({nums[i],i});
        
        }
        int l=0,r=nums.size()-1;
        sort(result.begin(),result.end());
        while(l<=r){
            if(result[l].first+result[r].first==target){
                return {result[l].second,result[r].second};
            }
            else if(result[l].first+result[r].first<target){
                l++;
            }
            else{
                r--;
            }
        }
        return {-1,-1};
    }
};