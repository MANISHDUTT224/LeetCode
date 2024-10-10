class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        stack<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.empty()||nums[s.top()]>nums[i]){
                s.push(i);
            }
        }
        int maxwidth=0;
        for(int j=nums.size()-1;j>=0;j--){
            while(!s.empty() && nums[s.top()]<=nums[j]){
               maxwidth=max(maxwidth,j-s.top());
               s.pop();
            }
        }
        return maxwidth;
    }
};