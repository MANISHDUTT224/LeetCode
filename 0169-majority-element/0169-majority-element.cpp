class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele,cnt=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                cnt++;
                ele=nums[i];
            }
            else if(nums[i]!=ele){
                cnt--;
            }
            else{
                cnt++;
            }
        }
        int cnt1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele){
                cnt1++;
            }
        }
        if(cnt1>=n/2){
            return ele;
        }
        return ele;
    }
};