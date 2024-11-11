class Solution {
public:
    
    int getmax(vector<int> & nums){
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
        }
        return maxi;
    }
    bool primeSubOperation(vector<int>& nums) {
        int maxele=getmax(nums);
        vector<bool>sieve(maxele+1,true);
        sieve[1]=false;
        for(int i=2;i<=sqrt(maxele+1);i++){
            if(sieve[i]){
                for(int j=i*i;j<=maxele;j+=i){
                    sieve[j]=false;
                }
            }
        }
        int curvalue=1;
        int i=0;
        while(i<nums.size()){
            int diff=nums[i]-curvalue;
            if(diff<0){
                return false;
            }
            if(sieve[diff]==true || diff==0){
                curvalue++;
                i++;
            }
            else{
                curvalue++;
            }
        }
        return true;
    }
};
