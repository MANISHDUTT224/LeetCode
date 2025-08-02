class Solution {
public:
    int majorityElement(vector<int>& nums) {
     int n=nums.size();
     int ele=INT_MIN;
     int c=0;
     for(int i=0;i<n;i++){
        if(ele==INT_MIN || c==0){
            ele=nums[i];
            c++;
        }
        else if(nums[i]==ele){
            c++;
        }
        else{
            c--;
        }
     }   
     int cnt=0;
     for(int i=0;i<n;i++){
        if(nums[i]==ele){
            cnt++;
        }
     }
     if(cnt>=(n/2)){
        return ele;
     }
     return -1;
    }
};