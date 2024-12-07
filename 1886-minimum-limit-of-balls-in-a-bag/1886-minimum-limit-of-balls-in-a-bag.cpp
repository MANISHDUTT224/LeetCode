class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<high){
            int mid=low+(high-low)/2;
            int ops=0;
            for(int n:nums){
                if((ops+=(n-1)/mid)>maxOperations){
                    break;
                }
            }
            ops<=maxOperations?high=mid:low=mid+1;
        }
        return high;
    }
};