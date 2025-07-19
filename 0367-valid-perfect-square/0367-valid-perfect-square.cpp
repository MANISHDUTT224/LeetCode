class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=1,j=num;
        while(i<=j){
            int mid=i+(j-i)/2;
            long  long  val=(long long)mid*mid;
            if(val==num){
                return true;
            }
            else if(val<num){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return false;
    }
};