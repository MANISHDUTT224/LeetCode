class Solution {
public:
    int mySqrt(int x) {
        long long i=1,j=x,ans=-1;
        if(x<=1){
            return x;
        }
        while(i<=j){
            long  long mid=(i+j)/2;
             long long val=(long)mid*(long)mid;
            if(val<=(long long)x){
               ans=mid;
               i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};