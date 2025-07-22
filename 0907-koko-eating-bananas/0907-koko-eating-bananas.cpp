class Solution {
public:
    long getHours(vector<int>&arr,long mid){
        long sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=ceil((double)arr[i]/(double)mid);

        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long i=1;
        long j=*max_element(piles.begin(),piles.end());
        long ans=-1;
        while(i<=j){
            long mid=i+(j-i)/2;
            long hours=getHours(piles,mid);
            if(hours<=h){
               
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return i;
    }
};