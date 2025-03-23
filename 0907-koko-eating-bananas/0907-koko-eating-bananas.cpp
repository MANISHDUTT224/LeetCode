class Solution {
public:
    long findhours(int mid,vector<int>piles){
        long total=0;
        for(int pile:piles){
            total+=ceil((double)pile/(double)mid);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());
        int i=1,j=maxi;
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            long totalhours=findhours(mid,piles);
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