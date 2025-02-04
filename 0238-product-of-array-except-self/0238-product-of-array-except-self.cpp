class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n=nums.size();
    //    vector<int> prefix(n,1);
    //    vector<int> suffix(n,1);
    //    for(int i=1;i<n;++i){
    //     prefix[i]=prefix[i-1]*nums[i-1];
    //    }
    //    for(int i=n-2;i>=0;--i){
    //     suffix[i]=suffix[i+1]*nums[i+1];
    //    }
    //    vector<int> a(n);
    //    for(int i=0;i<n;++i){
    //     a[i]=prefix[i]*suffix[i];
    //    }
    int prd=1;
    map<int,int>mp;
    int zc=0;
    for(int i:nums){
        if(i!=0){
        prd*=i;
        }
        else{
            zc++;
        }
    }
    vector<int>a(n,0);
   if(zc==n){
    return a;
   }
    for(int i=0;i<n;i++){
        if(nums[i]==0 &&zc==1){
        a[i]=prd;
        }
        else if(!zc){
            a[i]=prd/nums[i];
        }
        

    }

       return a;
    }
};