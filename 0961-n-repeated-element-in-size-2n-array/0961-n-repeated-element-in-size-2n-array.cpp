class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
       unordered_map<int,int> mp;
       int a;
       for(int i=0;i<nums.size();i++){
           mp[nums[i]]++;
       }
       int n1=nums.size()/2;
       for(auto x:mp){
           //cout<<"Frequencies : "<<x.second<<" ";
           if(x.second==n1){
               a= x.first;
               break;
           }
       }
      // cout<<n1;
       return a;
        
    }
};