class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        int max=nums[n-1]+nums[n-2]+nums[n-3];
        if( n==3 || ans>=target ){
            return ans;
        }
        if(max<=target){
            return max;
        }
        int dist=abs(ans-target);
        int last=nums[0],num;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==last){
                continue;
            }
            last=num=nums[i];
            int j=i+1,k=n-1;
            while(j<k){
                int sum=num+nums[j]+nums[k];
                if(abs(sum-target)<dist){
                    ans=sum;
                    dist=abs(sum-target);
                }
                else if(sum==target){
                    return sum;
                }
                if(sum<target){
                    while(j<k && nums[j]==nums[j+1]){
                        j++;
                    }
                    j++;
                }
                else{
                    while(j<k && nums[k]==nums[k-1]){
                        k--;
                    }
                    k--;
                }
            }
        }
        return ans;

    }
};