class Solution {
public:
    int findPrefixSumN(int target){
        int lo=1,hi=50000,mid;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if((long)mid*(mid+1)/2>=target){
                hi=mid;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
    }
    int reachNumber(int target) {
        target=abs(target);
        int n=findPrefixSumN(target);
        if(target%2==(int)ceil(n/2.0)%2){
            return n;
        }
        return n%2==0?n+1:n+2;
    }
};