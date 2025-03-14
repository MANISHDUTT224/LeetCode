class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int maxCandies=0;
        for(int i=0;i<candies.size();i++){
            maxCandies=max(maxCandies,candies[i]);
        }
        int left=0,right=maxCandies;
        while(left<right){
            int mid=(left+right+1)/2;
            if(canAllocate(candies,k,mid)){
                left=mid;
            }
            else{
                right=mid-1;
            }
        }
        return left;
    }
    bool canAllocate(vector<int>&candies,long long k,int mid){
        long long int maxNumOfChildren=0;
        for(int i=0;i<candies.size();i++){
            maxNumOfChildren+=candies[i]/mid;
        }
        return maxNumOfChildren>=k;
    }
};