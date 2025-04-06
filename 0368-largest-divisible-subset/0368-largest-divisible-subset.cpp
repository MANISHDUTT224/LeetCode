class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>len(n,1),prev(n,-1);
        sort(nums.begin(),nums.end());
        int maxlen=INT_MIN,iMax=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0 && len[j]<len[i]+1){
                    len[j]=len[i]+1;
                    prev[j]=i;
                }
            }
            if(len[i]>maxlen){
                maxlen=len[i];
                iMax=i;
            }
        }
        vector<int>ans;
        for(int j=iMax;j!=-1;j=prev[j]){
            ans.push_back(nums[j]);
        }
        return ans;
    }
};