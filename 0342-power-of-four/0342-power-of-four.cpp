class Solution {
public:
    bool isPowerOfFour(int n) {
        int low=0,high=1e9,mid;
        while(low<=high){
            mid=(low+high)/2;
            if(pow(4,mid)==n){
                return true;
            }
            else if(pow(4,mid)<n){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;

        
    }
};