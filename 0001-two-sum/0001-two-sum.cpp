class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<pair<int,int>>nums;
        for(int i=0;i<arr.size();i++){
            nums.push_back({arr[i],i});
        }
        int l=0,r=n-1;
        sort(nums.begin(),nums.end());
        while(l<=r){
            if(nums[l].first+nums[r].first==target){
                return {nums[l].second,nums[r].second};
            }
            else if(nums[l].first+nums[r].first<target){
                l++;
            }
            else{
                r--;
            }
        }
        return {-1,-1};
    }
};