class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
       vector<int> ls;
       int el1=INT_MIN,el2=INT_MIN;
       int cnt1=0,cnt2=0;
       for(int i=0;i<nums.size();i++){
        if(cnt1==0 && nums[i]!=el2){
            cnt1=1;
            el1=nums[i];
        }
        else if(cnt2==0 && nums[i]!=el1){
            cnt2=1;
            el2=nums[i];
        }
        else if(nums[i]==el1){
            cnt1++;
        }
        else if(nums[i]==el2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
       }
       
       cnt1=0,cnt2=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]==el1){
            cnt1++;
        }
        else if(nums[i]==el2){
            cnt2++;
        }
       }
      
       int check=int(nums.size()/3);
       if(cnt1>check){
        ls.push_back(el1);
       }
       if(cnt2>check){
        ls.push_back(el2);
       }
       return ls;
    }
};