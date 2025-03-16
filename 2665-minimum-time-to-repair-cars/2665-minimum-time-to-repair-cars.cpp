class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low=1,high=1LL*cars*cars*ranks[0];
        while(low<high){
            long long mid=(low+high)/2,carsrepaired=0;
            for(auto rank:ranks){
                carsrepaired+=sqrt(1.0*mid/rank);
            }
            if(carsrepaired<cars){
                low=mid+1;

            }
            else{
                high=mid;
            }
        }
        return low;
    }
};