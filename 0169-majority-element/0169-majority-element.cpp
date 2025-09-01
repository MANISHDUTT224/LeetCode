class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=INT_MIN,cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=ele && cnt==0){
                ele=nums[i];
                cnt++;
            }
            else if(nums[i]==ele){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele){
                count++;
            }
        }
        return ele;
    }
};