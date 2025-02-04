class Solution {
public:
    int maxAscendingSum(vector<int>& arr) {
        int n=arr.size(),r=1;
        int sum=arr[0];
        int maxsum=0;
        maxsum=max(maxsum,sum);
        while(r<n){
          
                if(arr[r]>arr[r-1]){
                sum+=arr[r];
                }
                else{
                    sum=arr[r];
                }
                 maxsum=max(sum,maxsum);
                r++;
                 
            }
            return maxsum;
        }
    
};