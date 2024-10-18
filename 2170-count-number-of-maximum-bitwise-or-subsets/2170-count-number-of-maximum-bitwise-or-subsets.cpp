class Solution {
public:
    void backtrack(const vector<int> &nums,int index,int curor,int maxor,int &count){
        if(curor==maxor){
            count++;
        }
        for(int i=index;i<nums.size();i++){
            backtrack(nums,i+1,curor|nums[i],maxor,count);
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int maxor=0;
        for(int i:nums){
            maxor|=i;
        }
        int count=0;
        backtrack(nums,0,0,maxor,count);
        return count;
    }
};