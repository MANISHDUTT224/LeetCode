class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele,ele1;
        int cnt01=0,cnt02=0;
        for(int i=0;i<nums.size();i++){
            if(cnt01==0 && ele1!=nums[i]){
                cnt01++;
                ele=nums[i];
            }
            else if(cnt02==0 && ele!=nums[i]){
                cnt02++;
                ele1=nums[i];
            }
            else if(ele==nums[i]){
                cnt01++;
            }
            else if(ele1==nums[i]){
                cnt02++;
            }
            else{
                cnt01--;
                cnt02--;
            }
        }
        vector<int>res;
        int n=nums.size();
        int count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele){
                count1++;
            }
            else if(nums[i]==ele1){
                count2++;
            }
        }
        if(count1>n/3){
            res.push_back(ele);
        }
        if(count2>n/3){
            res.push_back(ele1);
        }
        return res;
    }
};