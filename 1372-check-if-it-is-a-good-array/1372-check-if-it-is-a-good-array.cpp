class Solution {
public:
    int GCD(int n,int m){
        while(n>0 && m>0){
            if(n>m){
                n%=m;
            }
            else{
                m%=n;
            }
        }
        if(n==0){
            return m;
        }
        return n;
    }
    bool isGoodArray(vector<int>& nums) {
        int gcd=nums[0];
        for(auto it:nums){
            gcd=GCD(gcd,it);
        }
        return gcd==1;
    }
};