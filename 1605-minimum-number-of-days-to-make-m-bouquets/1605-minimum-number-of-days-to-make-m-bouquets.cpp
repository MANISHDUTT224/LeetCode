class Solution {
public:
    bool Possible(vector<int>&bloomDay,int mid,int m,int k){
        int conlen=0,bouqets=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                conlen++;
            }
            else{
                bouqets+=conlen/k;
                conlen=0;
            }
        }
        bouqets+=conlen/k;
        return bouqets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int i=*min_element(bloomDay.begin(),bloomDay.end());
        int j=*max_element(bloomDay.begin(),bloomDay.end());
        long long val=m*1LL*k*1LL;
        if(val>bloomDay.size()){
            return -1;
        }
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(Possible(bloomDay,mid,m,k)){
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