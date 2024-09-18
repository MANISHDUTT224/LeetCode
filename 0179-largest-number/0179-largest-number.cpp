class Solution {
public:
    static bool comp(int a,int b){
        return to_string(a)+to_string(b)>to_string(b)+to_string(a);
    }
    string largestNumber(vector<int>& nums) {
        
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        sort(nums.begin(),nums.end(),comp);
        if(nums[0]==0){
            return "0";
        }
       string ans;
       for(int n:nums){
        ans+=to_string(n);
       }
       return ans;
    }
};