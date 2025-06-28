class Solution {
public:
    long getHours(vector<int>&piles,int mid){
        long total=0;
        for(int pile:piles){
            total+=ceil((double)pile/(double)mid);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1,j=*max_element(piles.begin(),piles.end());

        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            long totalhours=getHours(piles,mid);
            if(totalhours>h){
                i=mid+1;
            }
            else{
                ans=mid;
                j=mid-1;
            }
        }
        return ans;
    }
};