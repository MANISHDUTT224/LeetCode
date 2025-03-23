class Solution {
public:
  long findhours(vector<int> &v, int hourly) {
    long  totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)v[i]/(double)hourly);
    }
    return totalH;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());
        int i=1,j=maxi;
        int ans=INT_MIN;
        while(i<=j){
            int mid=(i+j)/2;
            long totalhours=findhours(piles,mid);
            if(totalhours<=h){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};