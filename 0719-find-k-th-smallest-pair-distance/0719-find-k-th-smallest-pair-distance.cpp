class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left=0,right=nums[n-1]-nums[0];
        int mid;
        while(left<right){
            mid=left+(right-left)/2;
            if(countpairs(nums,mid)<k){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        return left;
    }
    int countpairs(const vector<int>&nums,int k){
        int count=0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            while(j<nums.size() && nums[j]-nums[i]<=k){
                j++;
            }
            count+=(j-i-1);
        }
        return count;
    }
};