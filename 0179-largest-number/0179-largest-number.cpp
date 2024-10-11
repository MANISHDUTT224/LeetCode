class Solution {
public:
    static bool comp(int a,int b){
        return to_string(a)+to_string(b)>to_string(b)+to_string(a);
    }
    string largestNumber(vector<int>& nums) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=nums.size();
        sort(nums.begin(),nums.end(),comp);
        string ans="";
        if(nums[0]==0){
            return "0";
        }
        for(int i:nums){
            ans+=to_string(i);
        }
        return ans;
        
    }
};