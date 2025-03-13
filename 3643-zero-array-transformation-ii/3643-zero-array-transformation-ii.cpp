class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0,k=0;
        int n=nums.size();
        vector<int>diffarray(n+1);
        
        for(int i=0;i<n;i++){
            while(sum+diffarray[i]<nums[i]){
                k++;
            
            if(k>queries.size()){
                return -1;
            }
            int left=queries[k-1][0],right=queries[k-1][1],val=queries[k-1][2];
            if(right>=i){
                diffarray[max(left,i)]+=val;
                diffarray[right+1]-=val;
            }
            }
            sum+=diffarray[i];
        }
        return k;
    }
};