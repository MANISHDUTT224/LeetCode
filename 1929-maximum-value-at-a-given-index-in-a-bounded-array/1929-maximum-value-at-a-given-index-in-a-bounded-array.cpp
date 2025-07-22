class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long r=n-index-1;
        long l=index;
        long lo=1,hi=maxSum;
        int res=0;
         while(lo<=hi){
            long mid=lo+(hi-lo)/2;
            long ls=0,rs=0,m=mid-1;
            long sum=mid;
            if(r<=m){
                rs=m*(m+1)/2-(m-r)*(m-r+1)/2;
            }
            else{
                rs=m*(m+1)/2+(r-m)*1;
            }
            if(l<=m){
                ls=m*(m+1)/2-(m-l)*(m-l+1)/2;
            }
            else{
                ls=m*(m+1)/2+(l-m);
            }

             sum+=ls+rs;
            if(sum<=maxSum){
                res=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
            
         }
         return res;
    }
};