class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi=INT_MIN,ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    ans=(long long)(nums[i]-nums[j])*(long long)nums[k];
                    maxi=max(maxi,ans);
                }
            }
        }
        return (maxi<0)?0:maxi;

    }

};