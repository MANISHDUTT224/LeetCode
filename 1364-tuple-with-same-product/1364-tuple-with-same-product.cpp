class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>pairproducts;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pairproducts.push_back(nums[i]*nums[j]);
            }
        }
        sort(pairproducts.begin(),pairproducts.end());
        int lastproductseen=-1;
        int sameproductcount=0;
        int totaltuples=0;
        for(int prodindex=0;prodindex<pairproducts.size();prodindex++){
            if(pairproducts[prodindex]==lastproductseen){
                sameproductcount++;
            }
            else{
                int tuplecount=(sameproductcount-1)*(sameproductcount)/2;
                totaltuples+=tuplecount*8;
                lastproductseen=pairproducts[prodindex];
                sameproductcount=1;
            }
        }
        int tuplecount=(sameproductcount-1)*(sameproductcount/2);
        totaltuples+=tuplecount*8;
        return totaltuples;

    }
};