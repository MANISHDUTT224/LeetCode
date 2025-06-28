class Solution {
public:
    int mySqrt(int x) {
        long long i=1,j=x;
        if(x<=1){
            return x;
        }
        int ans;
        while(i<=j){
            long long mid=(i+j)/2;
            if(mid*mid<=(long long)x){
               ans=mid;
               i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return (int)ans;
    }
};