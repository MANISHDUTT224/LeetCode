class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum=0;
        
        for(int i:nums){
            sum+=i;
        }
        int rem=sum%p;
        if(rem==0){
            return 0;
        }
        return findsmallestsubarray(nums,p,rem);

    }
private:
    int findsmallestsubarray(vector<int>& nums,int p,int rem){
        long long prefixsum=0;
        unordered_map<int,int> prefixmap;
        prefixmap[0]=-1;
        int minlen=nums.size();
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            int targetrem=(prefixsum%p-rem+p)%p;
            if(prefixmap.find(targetrem)!=prefixmap.end()){
                 minlen=min(minlen,i-prefixmap[targetrem]);
            }
            prefixmap[prefixsum%p]=i;
        }
        return minlen<nums.size()?minlen:-1;
    }
};