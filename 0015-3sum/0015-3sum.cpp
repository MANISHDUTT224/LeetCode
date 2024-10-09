class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int target=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<target){
                    j++;
                }
                else if(sum>target){
                    k--;
                }
                else{
                    vector<int>ans={nums[i],nums[j],nums[k]};
                    res.push_back(ans);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                    }

                }
            }
        }
        return res;
    }
};